#include "algorithms/spn/spn_algorithm.hpp"

#include <cassert>
#include <stdexcept>

#define FMT_HEADER_ONLY
#include "utilities/fmt/format.h"

/*
    Here is where you should define the logic for the FCFS algorithm.
*/

SPNScheduler::SPNScheduler(int slice) {
    if (slice != -1) {
        throw("SPN must have a timeslice of -1");
    }
}

std::shared_ptr<SchedulingDecision> SPNScheduler::get_next_thread() {
    if(!spn_queue.empty()){
        SchedulingDecision decision;
        int thread_num = size();
        decision.explanation = "Selected from " + std::to_string(thread_num) + " threads. Will run to completion of burst.";
        decision.time_slice = -1;
        decision.thread = spn_queue.top();
        spn_queue.pop();
        std::shared_ptr<SchedulingDecision> schedule = std::make_shared<SchedulingDecision>(decision);  
        return schedule;
    }
       SchedulingDecision decision;
        decision.explanation = "No threads available for scheduling.";
        decision.time_slice = -1;
        decision.thread = nullptr;
        std::shared_ptr<SchedulingDecision> schedule = std::make_shared<SchedulingDecision>(decision);  
        return schedule;
}

void SPNScheduler::add_to_ready_queue(std::shared_ptr<Thread> thread) {
        if (thread->current_state == READY){
            spn_queue.push(thread->get_next_burst(CPU)->length,thread);
        }
}

size_t SPNScheduler::size() const {
       return spn_queue.size();
       
}
