#include "algorithms/fcfs/fcfs_algorithm.hpp"

#include <cassert>
#include <stdexcept>

#define FMT_HEADER_ONLY
#include "utilities/fmt/format.h"

/*
    Here is where you should define the logic for the FCFS algorithm.
*/

FCFSScheduler::FCFSScheduler(int slice) {
    if (slice != -1) {
        throw("FCFS must have a timeslice of -1");
    }
}

std::shared_ptr<SchedulingDecision> FCFSScheduler::get_next_thread() {
    if(!fcfs_queue.empty()){
        SchedulingDecision decision;
        int thread_num = size();
        decision.explanation = "Selected from " + std::to_string(thread_num) + " threads. Will run to completion of burst.";
        decision.time_slice = -1;
        decision.thread = fcfs_queue.front();
        fcfs_queue.pop();
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

void FCFSScheduler::add_to_ready_queue(std::shared_ptr<Thread> thread) {
        if (thread->current_state == READY){
            fcfs_queue.push(thread);
        }
}

size_t FCFSScheduler::size() const {
       return fcfs_queue.size();
}
