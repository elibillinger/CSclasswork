//
//  Astroid.cpp
//  Asteroid
//
//  Created by Eli Billinger on 4/15/22.
//

#include <stdio.h>
#include "Asteroid.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Game.h"
#include "Random.h"

Asteroid::Asteroid(Game* game) :Actor(game) {
    Vector2 pos = Random::GetVector(Vector2::Zero, Vector2(1024.0f,768.0f));
    SetPosition(pos);
    SetRotation(Random::GetFloat());
    
    SpriteComponent* asteroidSprite = new SpriteComponent(this);
    asteroidSprite->SetTexture(game->GetTexture("assets/Asteroid.png"));
    MoveComponent* moveComponent = new MoveComponent(this);
    moveComponent->SetForwardSpeed(150.0f);
    

    game->AddAstroid(this);
}

Asteroid::~Asteroid(){
    GetGame()->RemoveAstroid(this);
}

