#include "algorithms/mlfq/mlfq_algorithm.hpp"

#include <cassert>
#include <stdexcept>

#define FMT_HEADER_ONLY
#include "utilities/fmt/format.h"

/*
    Here is where you should define the logic for the MLFQ algorithm.
*/

MLFQScheduler::MLFQScheduler(int slice) {
    if (slice < 0) {
        throw("MLFQ must have a timeslice greater than 0");
    }
    
}

std::shared_ptr<SchedulingDecision> MLFQScheduler::get_next_thread() {
   for( int i = 0; i < 10; i++ ){
       if(!mlfq_queue[i].empty()){
           prio_queue = i;
           break;
       } else if ( i == 9) {
           prio_queue = 10;
       }
   }
   if(prio_queue < 10){
        SchedulingDecision decision;
        decision.time_slice = pow(2,prio_queue);
        time_slice = pow(2,prio_queue);
        decision.thread = mlfq_queue[prio_queue].top();
        std::string prior;
        if(decision.thread->priority == 0){
            prior = "SYSTEM";
        } else if (decision.thread->priority == 1){
            prior = "INTERACTIVE";
        } else if (decision.thread->priority == 2){
            prior = "NORMAL";
        } else {
            prior = "BATCH";
        }
        int runtime = mlfq_queue[prio_queue].top()->queue_service_time;
        mlfq_queue[prio_queue].top()->queue_service_time += mlfq_queue[prio_queue].top()->get_next_burst(CPU)->length;
        decision.explanation = "Selected from queue " + std::to_string(prio_queue) + " (priority = " + prior + ", runtime = " + std::to_string(runtime) + "). Will run for at most "+std::to_string(decision.time_slice) +" ticks.";
        mlfq_queue[prio_queue].pop();
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

void MLFQScheduler::add_to_ready_queue(std::shared_ptr<Thread> thread) {
         if (thread->current_state == READY){
            int thread_queue = thread->previous_queue;
            if(thread->queue_service_time <  pow(2,thread_queue)){
                 mlfq_queue[thread->previous_queue].push(thread->priority,thread);
            } else {
                thread->previous_queue+=1;
                thread->queue_service_time = 0;
                mlfq_queue[thread->previous_queue].push(thread->priority,thread);
            }
           
            
        }
}


size_t MLFQScheduler::size() const {
       return mlfq_queue[0].size();
}
