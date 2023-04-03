//
//  BGSpriteComponent.cpp
//  Scrolling Game
//
//  Created by Eli Billinger on 4/6/22.
//

#include <stdio.h>
#include "BGSpriteComponent.h"
#include "Actor.h"

BGSpriteComponent::BGSpriteComponent(Actor* pActorOwner): SpriteComponent(pActorOwner){
}

BGSpriteComponent::~BGSpriteComponent(){
}

void BGSpriteComponent::Update(float deltaTime){
    SpriteComponent::Update(deltaTime);
    for(auto& texture : _pBGTextures){
        //Update x offset
        texture.offset.x += _pScrollSpeed * deltaTime;
        if(texture.offset.x < -_pScreenSize.x){
            texture.offset.x = ((_pBGTextures.size() - 1) * _pScreenSize.x -1);
        }
    }
}

void BGSpriteComponent::Draw(SDL_Renderer *pRenderer){
    for(auto& texture : _pBGTextures){
        if(texture.texture != nullptr){
            SDL_Rect r;
            r.w = (int)(_pScreenSize.x);
            r.h = (int)(_pScreenSize.y);
            r.x = (int)(_pActorOwner->GetPosition().x - r.w / 2 + texture.offset.x);
            r.y = (int)(_pActorOwner->GetPosition().y - r.h / 2 + texture.offset.y);
            SDL_RenderCopy(pRenderer, texture.texture, nullptr, &r);
        }
    }
}

void BGSpriteComponent::SetBGTextures(const std::vector<SDL_Texture *> &textures){
    int count = 0;
    for (auto texture : textures)
    {
        BGTexture tex;
        tex.texture = texture;
        tex.offset.x = count * _pScreenSize.x;
        tex.offset.y = 0;
        _pBGTextures.emplace_back(tex);
        count++;
    }
}

void BGSpriteComponent::SetScreenSize(const Vector2 &size){
    _pScreenSize = size;
}

void BGSpriteComponent::SetScrollSpeed(float speed){
    _pScrollSpeed = speed;
}
