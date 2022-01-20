/**
 * This file contains implementations for methods in the Process class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "process/process.h"

using namespace std;


Process* Process::read_from_input(std::istream& in) {
    vector<Page*> pages;
    size_t num_bytes = 0;
    while(!in.eof()){   
        pages.push_back(Page::read_from_input(in));
    }
    for(int i = 0; i < pages.size(); i++){
        num_bytes += pages[i]->size();
    }
   
    return new Process(num_bytes,pages);
}


size_t Process::size() const
{
    return this->num_bytes;
}


bool Process::is_valid_page(size_t index) const
{
    if(pages[index]){
        return true;
    } else {
        return false;
    }
}


size_t Process::get_rss() const
{   
    size_t rss = 0;
    for(int i = 0; i < pages.size(); i++){
        if(page_table.rows[i].present){
            rss++;
        }
    }
    return rss;
}


double Process::get_fault_percent() const
{
    if(page_faults == 0 || memory_accesses == 0){
        return 0.0;
    } else {
        double percent = (double) page_faults/ (double)memory_accesses * 100.0;
        return percent;
    }
    
}
