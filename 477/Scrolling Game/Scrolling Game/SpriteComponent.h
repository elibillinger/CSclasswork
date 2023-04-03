#pragma once

#include "Component.h"
#include "SDL2/SDL.h"

class SpriteComponent : public Component
{
public:
	SpriteComponent(class Actor* pActorOwner);
	~SpriteComponent();

	virtual void Draw(SDL_Renderer* pRenderer);
	void SetTexture(SDL_Texture* pTexture);

private:
	SDL_Texture* _pTexture;
	int _nWidth;
	int _nHeight;
};

