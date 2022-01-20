#include "algorithms/priority/priority_algorithm.hpp"

#include <cassert>
#include <stdexcept>

#define FMT_HEADER_ONLY
#include "utilities/fmt/format.h"

/*
    Here is where you should define the logic for the PRIORITY algorithm.
*/

PRIORITYScheduler::PRIORITYScheduler(int slice) {
    if (slice < 0) {
        throw("RR must have a timeslice greater than 0");
    }
    
}

std::shared_ptr<SchedulingDecision> PRIORITYScheduler::get_next_thread() {
   if(!prio_queue.empty()){
        SchedulingDecision decision;
        decision.time_slice = -1;
        decision.thread = prio_queue.top();
        if(decision.thread->priority == SYSTEM){
                prio = 0;
        } else if(decision.thread->priority == INTERACTIVE) {
                prio = 1;
        } else if(decision.thread->priority == NORMAL){
                prio = 2;
        } else {
                prio = 3;
        }
        decision.explanation = " [S: " + std::to_string(prio_count[0]) + " I: " + std::to_string(prio_count[1]) + " N: " + std::to_string(prio_count[2]) + " B: " + std::to_string(prio_count[3])+ "] -> [S: ";
        prio_count[prio]--;
        decision.explanation = decision.explanation + std::to_string(prio_count[0]) + " I: " + std::to_string(prio_count[1]) + " N: " + std::to_string(prio_count[2]) + " B: " + std::to_string(prio_count[3])+ "]. Will run to completion of burst.";
        prio_queue.pop();
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

void PRIORITYScheduler::add_to_ready_queue(std::shared_ptr<Thread> thread) {
         if (thread->current_state == READY){
            prio_queue.push(thread->priority,thread);
            if(thread->priority == SYSTEM){
                prio_count[0]++;
        } else if(thread->priority == INTERACTIVE) {
                prio_count[1]++;
        } else if(thread->priority == NORMAL){
                prio_count[2]++;
        } else {
                prio_count[3]++;
        }
        }
}

size_t PRIORITYScheduler::size() const {
       return prio_queue.size();
}
