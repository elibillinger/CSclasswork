#pragma once

#include "SDL2/SDL.h"
#include <vector>
#include <string>
#include <map>
using namespace std;

#include "Actor.h"

// Generic Game class.
class Game
{
public:
	Game();
	~Game();

	// Initialize the game.
	bool Initialize();

	// Run the game loop until the game is over.
	void RunLoop();

	// Shutdown the game.
	void Shutdown();

	// Add/Remove an Actor to/from the vector of actors.
	void AddActor(Actor* pActor);
	void RemoveActor(Actor* pActor);

    // Add/Remove a Sprite to/from the vector of sprites.
    void AddSprite(class SpriteComponent* pSprite);
    void RemoveSprite(class SpriteComponent* pSprite);
    
	// A way for Actors to get an SDL_Texture for some image.
	SDL_Texture* GetTexture(const string& filename);

private:
	void _processInput();

	void _updateGame();

	void _generateOutput();

	// Load and unload data specific to this game.
	void _loadData();
	void _unloadData();

	// SDL window and renderer.
	SDL_Window* _pWindow;
	SDL_Renderer* _pRenderer;

	// Is the game still running.
	bool _bIsRunning;
	Uint32 _nTickCount;

	// All the actors in the game.
	vector<Actor*> _vecActors;

	// TODO: All the sprites in the game.
    std::vector<class SpriteComponent*> _vecSprites;
    
	// All the textures in the game mapped by filename.
	map<string, SDL_Texture*> _mapTextures;

};

