//
//  MoveComponent.cpp
//  Asteroid
//
//  Created by Eli Billinger on 4/4/22.
//

#include <stdio.h>
#include "MoveComponent.h"
#include "Actor.h"
#include "Math.h"

MoveComponent::MoveComponent(Actor* pActorOwner)
: Component(pActorOwner) {
    _fAngularSpeed = 0.0;
    _fForwardSpeed = 0.0;
}

MoveComponent::~MoveComponent(){
}

void MoveComponent::Update(float deltaTime){
    if(!Math::NearZero(_fAngularSpeed)){
        float rot = _pOwner->GetRotation();
        rot += _fAngularSpeed * deltaTime;
        _pOwner->SetRotation(rot);
    }
    
    if(!Math::NearZero(_fForwardSpeed)){
        Vector2 pos = _pOwner->GetPosition();
        pos += _pOwner->GetForward() * _fForwardSpeed * deltaTime;
        
        //TODO: Screen wrapping
        // Once position x,y leave the screen, set them to the other side of the screen
        
        _pOwner->SetPosition(pos);
    }
}
