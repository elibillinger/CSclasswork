// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "SDL2/SDL.h"
#include <map>
#include <string>
#include <vector>
using namespace std;

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);
	
	SDL_Texture* GetTexture(const std::string& fileName);
    
    void AddAstroid(class Asteroid* astroid);
    void RemoveAstroid(class Asteroid* astroid);
    

private:
	void _processInput();
	void _updateGame();
	void _generateOutput();
	void _loadData();
	void _unloadData();
	
	// Map of textures loaded
	map<std::string, SDL_Texture*> _mapTextures;

	// All the actors in the game
	std::vector<class Actor*> _vecActors;
	
	// All the sprite components drawn
	std::vector<class SpriteComponent*> _vecSprites;

	SDL_Window* _pWindow;
	SDL_Renderer* _pRenderer;
	Uint32 _nTicksCount;
	bool _bIsRunning;
    
    std::vector<class Asteroid*> _vecAstroids;
};
