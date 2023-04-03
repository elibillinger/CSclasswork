//
//  InputComponent.cpp
//  Asteroid
//
//  Created by Eli Billinger on 4/6/22.
//

#include <stdio.h>
#include "Actor.h"
#include "InputComponent.h"

InputComponent::InputComponent(Actor* pOwner): MoveComponent(pOwner){
    _nForwardKey = 0;
    _nBackwardKey = 0;
    _nClockwiseKey = 0;
    _nCounterClockwiseKey = 0;
}

InputComponent::~InputComponent(){
    
}

void InputComponent::ProcessInput(const Uint8 *keyboardState){
    //calculate the forward spped of this MoveComponent
    float forwardSpeed = 0.0f;
    if(keyboardState[_nForwardKey]){
        forwardSpeed += _nMaxForwardSpeed;
        
    }
    if(keyboardState[_nBackwardKey]){
        forwardSpeed -= _nMaxForwardSpeed;

    }
    SetForwardSpeed(forwardSpeed);

    //Calculate the Angular Speed
    float angularSpeed = 0.0f;
    if(keyboardState[_nClockwiseKey]){
        angularSpeed += _nMaxAngularSpeed;
        
    }
    if(keyboardState[_nCounterClockwiseKey]){
        angularSpeed -= _nMaxAngularSpeed;
        
    }
    SetAngularSpeed(angularSpeed);
}
