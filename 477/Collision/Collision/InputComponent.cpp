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
        forwardSpeed += 10;
        //TODO: make this a _nMaxForwardSpeed attribute
    }
    if(keyboardState[_nBackwardKey]){
        forwardSpeed -= 10;
        //TODO: make this a _nMaxForwardSpeed attribute
    }
    _fForwardSpeed = forwardSpeed;
    
    //Calculate the Angular Speed
    float angularSpeed = 0.0f;
    if(keyboardState[_nClockwiseKey]){
        angularSpeed += 10;
        //TODO: make this a _nMaxAngularSpeed attribute
    }
    if(keyboardState[_nCounterClockwiseKey]){
        angularSpeed -= 10;
        //TODO: make this a _nMaxAngularSpeed attribute
    }
    _fAngularSpeed = angularSpeed;
}
