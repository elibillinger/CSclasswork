// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Component.h"
#include "Actor.h"

Component::Component(Actor* owner)
	:_pOwner(owner)
{
	// Add to actor's vector of components
    _pOwner->AddComponent(this);
}

Component::~Component()
{
    _pOwner->RemoveComponent(this);
}

void Component::Update(float deltaTime)
{
}
