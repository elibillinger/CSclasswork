#include "Game.h"
#include "SDL2_image/SDL_image.h"
#include "SpriteComponent.h"
#include "Actor.h"
#include "BGSpriteComponent.h"

Game::Game() {
	_pWindow = nullptr;
	_pRenderer = nullptr;
	_bIsRunning = true;
}

Game::~Game() {
}

// Initialize the game.
bool Game::Initialize() {
	// Initialize SDL.
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	// Create the SDL window.
	_pWindow = SDL_CreateWindow("Component-based game", 100, 100, 1024, 768, 0);
	if (_pWindow == nullptr) {
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	// Create the SDL renderer for all drawing.
	_pRenderer = SDL_CreateRenderer(_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (_pRenderer == nullptr) {
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}
    
    if (IMG_Init(IMG_INIT_PNG) == 0) {
        SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
        return false;
    }

	_nTickCount = SDL_GetTicks();

	// Load the data for this game.
	_loadData();

	return true;
}

// Run the overall game loop.
void Game::RunLoop() {
	// Keep running the game until it is over.
	while (_bIsRunning) {
		_processInput();
		_updateGame();
		_generateOutput();
	}
}

// Shutdown the game.
void Game::Shutdown() {
	// Unload the data for this game.
	_unloadData();

	// Cleanup SDL.
	SDL_DestroyRenderer(_pRenderer);
	SDL_DestroyWindow(_pWindow);
	SDL_Quit();
}

void Game::_processInput() {
	// Poll for events in the window.
	// Needed to keep the window open.
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				_bIsRunning = false;
				break;
		}
	}

	// Get the entire state of the keyboard in an unsigned integer array.
	const Uint8* state = SDL_GetKeyboardState(NULL);

	// Check state of particular keys.
	if (state[SDL_SCANCODE_ESCAPE]) {
		_bIsRunning = false;
	}
}

void Game::_updateGame() {
	// Set the deltaTime game time.
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), _nTickCount + 16));

	float deltaTime = (SDL_GetTicks() - _nTickCount) / 1000.0f;
	_nTickCount = SDL_GetTicks();

	// Update all the actors.
	for (Actor* pActor : _vecActors) {
		pActor->Update(deltaTime);
	}

	// Delete any deceased actors.
	vector<Actor*> deadActors;
	for (Actor* pActor : _vecActors) {
		if (pActor->GetState() == Actor::DEAD) {
			deadActors.push_back(pActor);
		}
	}

	for (Actor* pActor : deadActors) {
		delete pActor;
	}
}

void Game::_generateOutput() {
	// Set background to blue.
	SDL_SetRenderDrawColor(_pRenderer, 0, 0, 255, 255);

	// Clear the back buffer to be ready to draw.
	SDL_RenderClear(_pRenderer);

    // Draw all sprite components
    for (auto sprite : _vecSprites)
    {
        sprite->Draw(_pRenderer);
    }
    
	// Swap the front and back buffers.
	SDL_RenderPresent(_pRenderer);
}

// Add an Actor to _vecActors.
void Game::AddActor(Actor* pActor) {
	_vecActors.push_back(pActor);
}

// Remove and Actor from _vecActors.
void Game::RemoveActor(Actor* pActor) {
	vector<Actor*>::iterator iter = find(_vecActors.begin(), _vecActors.end(), pActor);
	if (iter != _vecActors.end()) {
		iter_swap(iter, _vecActors.end() - 1);
		_vecActors.pop_back();
	}
}

// Load data specific to this game.
void Game::_loadData() {
    // Create actor for the background (this doesn't need a subclass)
    Actor* tempActor = new Actor(this);
    tempActor->SetPosition(Vector2(512.0f, 384.0f));
    // Create the "far back" background
    BGSpriteComponent* backgroundOne = new BGSpriteComponent(tempActor);
    backgroundOne->SetScreenSize(Vector2(1024.0f, 768.0f));
    std::vector<SDL_Texture*> backgroundOneTextures = {
        GetTexture("assets/Farback01.png"),
        GetTexture("assets/Farback02.png")
    };
    backgroundOne->SetBGTextures(backgroundOneTextures);
    backgroundOne->SetScrollSpeed(-20.0f);
    // Create the closer background
    BGSpriteComponent* backgroundTwo = new BGSpriteComponent(tempActor);
    backgroundTwo->SetScreenSize(Vector2(1024.0f, 768.0f));
    std::vector<SDL_Texture*> backgroundTwoTextures = {
        GetTexture("assets/Stars.png"),
        GetTexture("assets/Stars.png")
    };
    backgroundTwo->SetBGTextures(backgroundTwoTextures);
    backgroundTwo->SetScrollSpeed(-50.0f);
}

// Unload the data specific to this game.
void Game::_unloadData() {
    // Delete actors
    // Because ~Actor calls RemoveActor, have to use a different style loop
    while (!_vecActors.empty()) {
        delete _vecActors.back();
    }

    // Destroy textures
    for (auto i : _mapTextures) {
        SDL_DestroyTexture(i.second);
    }
    _mapTextures.clear();
}

// Return an SDL_Texture given a filename.
SDL_Texture* Game::GetTexture(const string& filename) {
	// Is this filename already in the map.
	map<string, SDL_Texture*>::iterator it = _mapTextures.find(filename);
	if (it != _mapTextures.end()) {
		return it->second;
	}
	else {
		SDL_Surface* surf = IMG_Load(filename.c_str());
		if (surf == nullptr) {
			SDL_Log("Failed to load filename %s", filename.c_str());
			return nullptr;
		}

		// Create a texture from the surface.
		SDL_Texture* pTex = SDL_CreateTextureFromSurface(_pRenderer, surf);
		if (pTex == nullptr) {
			SDL_Log("Failed to create texture from filename %s", filename.c_str());
			return nullptr;
		}

		_mapTextures.emplace(filename, pTex);
		return pTex;
	}
}

void Game::AddSprite(SpriteComponent* sprite)
{
    // Inserts element before position of iterator
    _vecSprites.push_back(sprite);
}

void Game::RemoveSprite(SpriteComponent* sprite)
{
    vector<SpriteComponent*>::iterator iter = find(_vecSprites.begin(), _vecSprites.end(), sprite);
    if (iter != _vecSprites.end()) {
        _vecSprites.erase(iter);
    }
}
