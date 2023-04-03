// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include <cstdint>
#include "SDL2/SDL.h"


class Component
{
public:
	// Constructor
	Component(class Actor* owner);
	// Destructor
	virtual ~Component();
	// Update this component by delta time
	virtual void Update(float deltaTime);
    
    virtual void ProcessInput(const Uint8* pKeyboardState) {}
	
protected:
	// Owning actor
	class Actor* _pOwner;
};
