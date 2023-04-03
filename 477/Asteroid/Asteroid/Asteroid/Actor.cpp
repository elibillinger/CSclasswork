// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Actor.h"
#include "Game.h"
#include "Component.h"
#include <algorithm>

Actor::Actor(Game* game)
	:_state(EActive)
	, _position(Vector2::Zero)
	, _fScale(1.0f)
	, _fRotation(0.0f)
	, _pGame(game)
{
	_pGame->AddActor(this);
}

Actor::~Actor()
{
	_pGame->RemoveActor(this);
	// Need to delete components
	// Because ~Component calls RemoveComponent, need a different style loop
	while (!_vecComponents.empty())
	{
		delete _vecComponents.back();
	}
}

void Actor::Update(float deltaTime)
{
	if (_state == EActive)
	{
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}

void Actor::UpdateComponents(float deltaTime)
{
	for (auto comp : _vecComponents)
	{
		comp->Update(deltaTime);
	}
}

void Actor::UpdateActor(float deltaTime)
{
}

void Actor::AddComponent(Component* component)
{
	// Inserts element before position of iterator
	_vecComponents.push_back(component);
}

void Actor::RemoveComponent(Component* component)
{
	auto iter = std::find(_vecComponents.begin(), _vecComponents.end(), component);
	if (iter != _vecComponents.end())
	{
        _vecComponents.erase(iter);
	}
}

void Actor::ProcessInput(const Uint8 *pkeyboardState){
    for (Component* pComponent : _vecComponents){
        pComponent->ProcessInput(pkeyboardState);
    }
}
