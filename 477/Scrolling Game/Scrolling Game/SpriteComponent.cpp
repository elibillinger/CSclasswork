#include "SpriteComponent.h"
#include "Actor.h"
#include "Game.h"


SpriteComponent::SpriteComponent(Actor* pActorOwner)
: Component(pActorOwner) {
    _pTexture = nullptr;
    _nWidth = 0;
    _nHeight = 0;
    
    // TODO: Add sprite to Game list via Actor Game pointer.
    _pActorOwner->GetGame()->AddSprite(this);
}


SpriteComponent::~SpriteComponent() {
    // TODO: Remove myself from Game list via Actor Game pointer.
    _pActorOwner->GetGame()->RemoveSprite(this);
}

void SpriteComponent::Draw(SDL_Renderer* pRenderer) {
    // Render my texture using SDL.
	if (_pTexture) {
		SDL_Rect r;
        r.w = static_cast<int>(_nWidth);
        r.h = static_cast<int>(_nHeight);
        // Center the rectangle around the position of the owner
        r.x = static_cast<int>(_pActorOwner->GetPosition().x - r.w / 2);
        r.y = static_cast<int>(_pActorOwner->GetPosition().y - r.h / 2);

        // Draw (have to convert angle from radians to degrees, and clockwise to counter)
        SDL_RenderCopyEx(pRenderer,
            _pTexture,
            nullptr,
            &r,
            -Math::ToDegrees(0),
            nullptr,
            SDL_FLIP_NONE);
	}
}

// Setter for my texture.
void SpriteComponent::SetTexture(SDL_Texture* pTexture) {
	_pTexture = pTexture;
	SDL_QueryTexture(pTexture, nullptr, nullptr, &_nWidth, &_nHeight);
}
