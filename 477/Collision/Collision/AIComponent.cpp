//
//  AIComponent.cpp
//  Collision
//
//  Created by Eli Billinger on 4/13/22.
//

#include <stdio.h>
#include "AIComponent.h"
#include "Actor.h"
#include "AIState.h"

AIComponent::AIComponent(Actor* pOwner)
: Component(pOwner){
    _pCurrentState = nullptr;
}

AIComponent::~AIComponent(){
    //Cleanup the AIStates that were allocated on the heap
    std::map<std::string,AIState*>::iterator it = _mapAIStates.begin();
    while(it != _mapAIStates.end()){
        delete it->second;
        it++;
    }
}

void AIComponent::Update(float deltaTime){
    if(_pCurrentState != nullptr){
        _pCurrentState->Update(deltaTime);
    }
}

void AIComponent::RegisterState(class AIState* pState){
    //Add this state to internal map
    _mapAIStates.emplace(pState->GetName(),pState);
}

void AIComponent::ChangeState(const std::string &stateName){
    if(_pCurrentState != nullptr){
        _pCurrentState->OnExit();
    }
    
    //try to find the new state from the map
    std::map<std::string,AIState*>::iterator it = _mapAIStates.find(stateName);
    if(it != _mapAIStates.end()){
        _pCurrentState = it->second;
        //Enter into new state
        _pCurrentState->OnEnter();
    } else {
        SDL_Log("Could not find AIState %s in state map",stateName);
        _pCurrentState = nullptr;
    }
}
