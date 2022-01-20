#include "algorithms/rr/rr_algorithm.hpp"

#include <cassert>
#include <stdexcept>

#define FMT_HEADER_ONLY
#include "utilities/fmt/format.h"

/*
    Here is where you should define the logic for the RR algorithm.
*/

RRScheduler::RRScheduler(int slice) {
    if (slice < 0) {
        throw("RR must have a timeslice greater than 0");
    }
    
}

std::shared_ptr<SchedulingDecision> RRScheduler::get_next_thread() {
   if(!rr_queue.empty()){
        SchedulingDecision decision;
        int thread_num = size();
        decision.explanation = "Selected from " + std::to_string(thread_num) + " threads. Will run for at most "+std::to_string(time_slice) +" ticks.";
        decision.time_slice = time_slice;
        decision.thread = rr_queue.front();
         rr_queue.pop();
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

void RRScheduler::add_to_ready_queue(std::shared_ptr<Thread> thread) {
        if (thread->current_state == READY){
            rr_queue.push(thread);
        }
}

size_t RRScheduler::size() const {
       return rr_queue.size();
}
