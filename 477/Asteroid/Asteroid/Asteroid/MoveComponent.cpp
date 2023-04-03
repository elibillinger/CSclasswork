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
        
        // Once position x,y leave the screen, set them to the other side of the screen
        if( pos.x < 0.0f){
            pos.x = 1024.0f;
        } else if (pos.x > 1024.0f){
            pos.x = 0.0f;
        }
        
        if( pos.y < 0.0f){
            pos.y = 768.0f;
        } else if (pos.y > 768.0f){
            pos.y = 0.0f;
        }
        
        _pOwner->SetPosition(pos);
    }
}
