#include "algorithms/cfs/cfs_algorithm.hpp"

#include <cassert>
#include <stdexcept>

#define FMT_HEADER_ONLY
#include "utilities/fmt/format.h"

/*
    Here is where you should define the logic for the cfs algorithm.
*/

        
CFSScheduler::CFSScheduler(int slice) {
    if (slice < 0) {
        throw("CFS must have a timeslice greater than 0");
    }
    
}

std::shared_ptr<SchedulingDecision> CFSScheduler::get_next_thread() {
   if(!cfs_queue.empty()){
        SchedulingDecision decision;
        sched_latency = ((float)48/((float)size()));
        decision.thread = cfs_queue.top();
        int weight;
        if(decision.thread->priority == 0){
            weight = 88761;
        } else if (decision.thread->priority == 1){
            weight = 29154;
        } else if (decision.thread->priority == 2){
            weight = 1024;
        } else {
            weight = 15;
        }
        int sum_weights = 0;
       temp_queue = cfs_queue;
       while (!temp_queue.empty())
        {
               std::shared_ptr<Thread> temp_thread = temp_queue.top();
               if(temp_thread->priority == 0){
                        sum_weights +=  88761;
                } else if (temp_thread->priority == 1){
                        sum_weights += 29154; 
                }else if (temp_thread->priority == 2){
                        sum_weights +=  1024;
                } else {
                        sum_weights +=  15;
                }
                temp_queue.pop();
        }
        int calculated_time_slice = (int)(((((float)weight)/((float)sum_weights)))*((float) sched_latency));
        if(calculated_time_slice <= min_granularity){
                decision.time_slice = min_granularity;
                time_slice = min_granularity;
        } else {
                decision.time_slice = calculated_time_slice;
                time_slice = calculated_time_slice;
        }

        decision.explanation = "Selected from " + std::to_string(size()) + " threads (vruntime = " + std::to_string(decision.thread->vruntime) +  "). Will run for at most "+std::to_string(decision.time_slice) +" ticks.";
        cfs_queue.pop();
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

void CFSScheduler::add_to_ready_queue(std::shared_ptr<Thread> thread) {
         if (thread->current_state == READY){
                int weight;
                if(thread->priority == 0){
                        weight = 88761;
                } else if (thread->priority == 1){
                        weight = 29154;
                } else if (thread->priority == 2){
                        weight = 1024;
                } else {
                        weight = 15;
                }
                int runtime = thread->service_time;
                float v_runtime = ((float) 1024)/((float) weight); 
                thread->vruntime = (int) ( v_runtime *(float) runtime);
                cfs_queue.push(thread->vruntime,thread);
        }
}


size_t CFSScheduler::size() const {
       return cfs_queue.size();
}
