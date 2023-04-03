//
//  Ship.cpp
//  Asteroid
//
//  Created by Eli Billinger on 4/15/22.
//

#include <stdio.h>
#include "Ship.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "Game.h"

Ship::Ship(Game* game)
    :Actor(game)
{
    // create sprite
    SpriteComponent* shipSprite = new SpriteComponent(this);
    shipSprite->SetTexture(game->GetTexture("assets/Ship.png"));

    // Set keys for movement
    InputComponent* input = new InputComponent(this);
    input->SetForwardKey(SDL_SCANCODE_W);
    input->SetBackKey(SDL_SCANCODE_S);
    input->SetClockwiseKey(SDL_SCANCODE_A);
    input->SetCounterClockwiseKey(SDL_SCANCODE_D);
    input->SetMaxForwardSpeed(100.0f);
    input->SetMaxAngularSpeed(1);
}

