/**
 * This file contains implementations for the methods defined in the Simulation
 * class.
 *
 * You'll probably spend a lot of your time here.
 */

#include "simulation/simulation.h"
#include <stdexcept>

Simulation::Simulation(FlagOptions& flags)
{
    this->flags = flags;
    this->frames.reserve(flags.max_frames);
    
}

void Simulation::run() {
    
    for(int i = 0; i < 512; i++){
        this->free_frames.push_back(i);
    }
    for( auto entry : processes){
        for( auto value : entry.second->page_table.rows){
            value.last_accessed_at = 1e6;
            value.loaded_at = 0;
        }
    }
        for(auto address : this->virtual_addresses){
            if(address.page > processes[address.process_id]->pages.size()){
                std::cout << address << "\n";
                std::cout << "SEGFAULT - INVALID PAGE" << "\n";
                exit(0);
            } 
            timer++;
            perform_memory_access(address);
        }
    
    print_summary();
}

char Simulation::perform_memory_access(const VirtualAddress& virtual_address) {
    int pid = virtual_address.process_id;
    size_t page_number = virtual_address.page;
     processes[pid]->memory_accesses++;
     processes[pid]->page_table.rows[page_number].last_accessed_at = timer;
    Frame frame;
    frame.set_page(processes[pid],page_number);
    this->frames.push_back(frame);
    if(processes[pid]->page_table.rows[page_number].present == 1){
       const PhysicalAddress& address = PhysicalAddress(processes[pid]->frame_map[page_number],virtual_address.offset);
        std::cout << virtual_address << "\n";
        std::cout <<  "    -> IN MEMORY " << "\n";
        std::cout << "    -> physical address "<<address << "\n";
        if(virtual_address.offset >= (size_t)63){
            std::cout << "SEGFAULT - INVALID OFFSET" << "\n";
            exit(0);
        }
        std::cout << "    -> RSS: "<<processes[pid]->get_rss() << "\n";
    } else {
        processes[pid]->pagesFIFO.push(page_number);
        processes[pid]->frames_used++;
        processes[pid]->page_faults++;
        handle_page_fault(processes[pid],virtual_address.page);
        std::cout << virtual_address << "\n";
        std::cout <<  "    -> PAGE FAULT " << "\n";
         const PhysicalAddress& address = PhysicalAddress(processes[pid]->frame_map[page_number],virtual_address.offset);
        std::cout << "    -> physical address "<<address << "\n";
        if(virtual_address.offset >= (size_t)63){
            std::cout << "SEGFAULT - INVALID OFFSET" << "\n";
            exit(0);
        }
        std::cout << "    -> RSS: "<< processes[pid]->get_rss() << "\n";  
    }
    return 0;
}

void Simulation::handle_page_fault(Process* process, size_t page) {
    page_faults++;
    if(process->frames_used <= flags.max_frames){
        process->page_table.rows[page].present = true;
        process->frame_map.insert(std::pair<size_t,int>(page,total_frames));
        total_frames++;
        free_frames.pop_front();
    } else {
        if(flags.strategy == ReplacementStrategy::FIFO){
            process->page_table.rows[process->pagesFIFO.front()].present = false;
            process->frame_map[page] = process->frame_map[process->pagesFIFO.front()];
            process->frame_map.erase(process->pagesFIFO.front());
            process->pagesFIFO.pop();
            process->page_table.rows[page].present = true; 
        } else if(flags.strategy == ReplacementStrategy::LRU){
            int oldest = process->page_table.rows.size()-1;
            for( int i =0; i < process->page_table.rows.size(); i++){
                if ( process->page_table.rows[i].present){
                    if(process->page_table.rows[i].last_accessed_at < process->page_table.rows[oldest].last_accessed_at)
                    oldest = i;
                }
            }
            process->page_table.rows[oldest].present = false;
            process->frame_map[page] = process->frame_map[oldest];
            process->frame_map.erase(oldest);
            process->page_table.rows[oldest].last_accessed_at = 1e6;
            process->page_table.rows[page].present = true; 
        }
    }
    
}

void Simulation::print_summary() {
    if (!this->flags.csv) {
        boost::format process_fmt(
            "Process %3d:  "
            "ACCESSES: %-6lu "
            "FAULTS: %-6lu "
            "FAULT RATE: %-8.2f "
            "RSS: %-6lu\n");

        for (auto entry : this->processes) {
            std::cout << process_fmt
                % entry.first
                % entry.second->memory_accesses
                % entry.second->page_faults
                % entry.second->get_fault_percent()
                % entry.second->get_rss();
        }

        // Print statistics.
        boost::format summary_fmt(
            "\n%-25s %12lu\n"
            "%-25s %12lu\n"
            "%-25s %12lu\n");

        std::cout << summary_fmt
            % "Total memory accesses:"
            % this->virtual_addresses.size()
            % "Total page faults:"
            % this->page_faults
            % "Free frames remaining:"
            % this->free_frames.size();
    }

    if (this->flags.csv) {
        boost::format process_fmt(
            "%d,"
            "%lu,"
            "%lu,"
            "%.2f,"
            "%lu\n");

        for (auto entry : processes) {
            std::cout << process_fmt
                % entry.first
                % entry.second->memory_accesses
                % entry.second->page_faults
                % entry.second->get_fault_percent()
                % entry.second->get_rss();
        }

        // Print statistics.
        boost::format summary_fmt(
            "%lu,,,,\n"
            "%lu,,,,\n"
            "%lu,,,,\n");

        std::cout << summary_fmt
            % this->virtual_addresses.size()
            % this->page_faults
            % this->free_frames.size();
    }
}

int Simulation::read_processes(std::istream& simulation_file) {
    int num_processes;
    simulation_file >> num_processes;

    for (int i = 0; i < num_processes; ++i) {
        int pid;
        std::string process_image_path;

        simulation_file >> pid >> process_image_path;

        std::ifstream proc_img_file(process_image_path);

        if (!proc_img_file) {
            std::cerr << "Unable to read file for PID " << pid << ": " << process_image_path << std::endl;
            return 1;
        }
        this->processes[pid] = Process::read_from_input(proc_img_file);
    }
    return 0;
}

int Simulation::read_addresses(std::istream& simulation_file) {
    int pid;
    std::string virtual_address;

    try {
        while (simulation_file >> pid >> virtual_address) {
            this->virtual_addresses.push_back(VirtualAddress::from_string(pid, virtual_address));
        }
    } catch (const std::exception& except) {
        std::cerr << "Error reading virtual addresses." << std::endl;
        std::cerr << except.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Error reading virtual addresses." << std::endl;
        return 1;
    }
    return 0;
}

int Simulation::read_simulation_file() {
    std::ifstream simulation_file;
    simulation_file.open(this->flags.filename);

    if (!simulation_file) {
        std::cerr << "Unable to open file: " << this->flags.filename << std::endl;
        return -1;
    }
    int error = 0;
    error = this->read_processes(simulation_file);

    if (error) {
        std::cerr << "Error reading processes. Exit: " << error << std::endl;
        return error;
    }

    error = this->read_addresses(simulation_file);

    if (error) {
        std::cerr << "Error reading addresses." << std::endl;
        return error;
    }

    if (this->flags.file_verbose) {
        for (auto entry: this->processes) {
            std::cout << "Process " << entry.first << ": Size: " << entry.second->size() << std::endl;
        }

        for (auto entry : this->virtual_addresses) {
            std::cout << entry << std::endl;
        }
    }

    return 0;
}
