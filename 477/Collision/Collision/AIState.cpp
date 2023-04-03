//
//  AIState.cpp
//  Collision
//
//  Created by Eli Billinger on 4/13/22.
//

#include <stdio.h>
#include "AIState.h"
#include "SDL2/SDL.h"

AIState::AIState(AIComponent* pOwner){
    _pOwner = pOwner;
}

AIState::~AIState(){
    
}

void AIPatrol::Update(float deltatime){
    
}

void AIPatrol::OnExit(){
    SDL_Log("Exiting %s state", GetName());
}

void AIPatrol::OnEnter(){
    SDL_Log("Entering %s state", GetName());
}

void AIAttack::Update(float deltatime){
    
}

void AIAttack::OnExit(){
    SDL_Log("Exiting %s state", GetName());
}

void AIAttack::OnEnter(){
    SDL_Log("Entering %s state", GetName());
}
