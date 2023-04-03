//
//  CircleComponent.cpp
//  Collision
//
//  Created by Eli Billinger on 4/11/22.
//

#include <stdio.h>
#include "Actor.h"
#include "CircleComponent.h"

CircleComponent::CircleComponent(Actor* pOwner)
: Component(pOwner){
    _fRadius = 0;
}

CircleComponent::~CircleComponent(){
    
}

const Vector2& CircleComponent::GetCenter() const {
    return _pOwner->GetPosition();
}

float CircleComponent::GetRadius() const {
    return _pOwner->GetScale()*_fRadius;
}

//Method to determine if this CircleComponent
// is colliding with other
bool CircleComponent::Intersect(const CircleComponent &other){
    //Calculate distance squared
    Vector2 diff = this->GetCenter() - other.GetCenter();
    float distSquared = diff.LengthSq();
    
    //Calculate sum of radii squared
    float raddiSquared = this->GetRadius() + other.GetRadius();
    raddiSquared *= raddiSquared;
    
    return distSquared <= raddiSquared;
}
