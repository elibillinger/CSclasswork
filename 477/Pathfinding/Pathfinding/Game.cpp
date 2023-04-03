//
//  Game.cpp
//  Pathfinding
//
//  Created by Eli Billinger on 3/14/22.
//

#include "Game.hpp"

Game::Game()
{
    _pWindow = nullptr;
    _pRenderer = nullptr;
    _bIsRunning = true;
    _nTickCount = 0;
    _nPaddleDir = 0;
    _nPaddleDir2 = 0;
    
}

Game::~Game()
{
    
}

// Initialize the game
bool Game::Initialize(){
    // Initialize SDL
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if (sdlResult != 0){
        SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
        return false;
    }
    
    _pWindow = SDL_CreateWindow("Pong", 100, 100, 1024, 768, 0);
    if (_pWindow == nullptr){
        SDL_Log("Failed to create window: %s\n", SDL_GetError());
        return false;
    }
    
    // Create the SDL renderer for all drawing
    _pRenderer = SDL_CreateRenderer(_pWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_PRESENTVSYNC);
    if (_pRenderer == nullptr){
        SDL_Log("Failed to create renderer: %s ", SDL_GetError());
    }
    
    // Initialize the paddle and ball positions
    _vecPaddlePos.x = 10.0f;
    _vecPaddlePos.y = 768.0f / 2.0f;
    
    _vecBallPos.x = 1024.0f / 2.0f;
    _vecBallPos.y = 500.0f;//768.0f / 2.0f;
    
    _vecBallVelocity.x = -200.0f;
    _vecBallVelocity.y = 235.0f;
    
    _vecPaddlePos2.x = 1009.0f;
    _vecPaddlePos2.y = 768.0f / 2.0f;
    
    return true;
}

// Run overall game loop
void Game::RunLoop(){
    // Keep running game until it is over
    while (_bIsRunning){
        _processInput();
        _updateGame();
        _generateOutput();
    }
}

//Shutdown game
void Game::Shutdown(){
    // Cleanup SDL
    SDL_DestroyRenderer(_pRenderer);
    SDL_DestroyWindow(_pWindow);
    SDL_Quit();
}

void Game::_processInput(){
    // Poll for events in the window
    // Needed to keep window open
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_QUIT:
                _bIsRunning = false;
                break;
            
        }
    }
    // Get the entire state of the keyboard in an unsigned int array
    const Uint8* state = SDL_GetKeyboardState(NULL);
    
    // Check the state of particular keys
    if (state[SDL_SCANCODE_ESCAPE]){
        _bIsRunning = false;
    }
    
    // w key so move paddle up
    if (state[SDL_SCANCODE_W]){
        _nPaddleDir = -1;
    }
    
    // s key so move paddle down
    if (state[SDL_SCANCODE_S]){
        _nPaddleDir = 1;
    }
    
    // i key so move paddle up
    if (state[SDL_SCANCODE_I]){
        _nPaddleDir2 = -1;
    }
    
    // k key so move paddle down
    if (state[SDL_SCANCODE_K]){
        _nPaddleDir2 = 1;
    }
}

void Game::_updateGame(){
    // Wait until 16ms have elapsed
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), _nTickCount + 16));
    
    // Delta time is the diff in ticks from last frame to this frame
    // Converteted to seconds
    float deltaTime = (SDL_GetTicks() - _nTickCount) / 1000.f;
    
    _nTickCount = SDL_GetTicks();
    
    // Update paddle position based on direction
    if (_nPaddleDir != 0){
        // Move paddle
        _vecPaddlePos.y += _nPaddleDir * 300.0f * deltaTime;
        //
        
        //Don't let paddle leave the screen
        if (_vecPaddlePos.y >= 668 || _vecPaddlePos.y <= 0){
            _nPaddleDir = 0;
        }
    }
    
    // Update paddle position based on direction
    if (_nPaddleDir2 != 0){
        // Move paddle
        _vecPaddlePos2.y += _nPaddleDir2 * 300.0f * deltaTime;
    
        //Don't let paddle leave the screen
        if (_vecPaddlePos2.y >= 668 || _vecPaddlePos2.y <= 0){
            _nPaddleDir2 = 0;
        }
    }
    
    // Update the ball position based on its velocity and deltaTime
    _vecBallPos.x += _vecBallVelocity.x * deltaTime;
    _vecBallPos.y += _vecBallVelocity.y * deltaTime;
    
    // Check for collision with paddle
    float diff = _vecPaddlePos.y - _vecBallPos.y;
    diff = (diff > 0.0f) ? diff : -diff;
    if (diff <= 100 && _vecBallPos.x <= 25 && _vecBallPos.x >= 20 && _vecBallVelocity.x < 0){
        // Collided with paddle so reverse direction
        _vecBallVelocity.x *= -1.0f;
    }
    // Check for collision with paddle2
    float diff2 = _vecPaddlePos2.y - _vecBallPos.y;
    diff2 = (diff2 > 0.0f) ? diff2 : -diff2;
    if (diff2 <= 100 && _vecBallPos.x <= 1009 && _vecBallPos.x >= 999 && _vecBallVelocity.x > 0){
        // Collided with paddle so reverse direction
        _vecBallVelocity.x *= -1.0f;
    }
    
    
    // Did ball collide with bottom wall
    if (_vecBallPos.y >= 768 - _THICKNESS && _vecBallVelocity.y > 0.0f){
        _vecBallVelocity.y *= -1;
    }
    
    // Did ball collide with top wall
    if (_vecBallPos.y <= 0 - _THICKNESS && _vecBallVelocity.y < 0.0f){
        _vecBallVelocity.y *= -1;
    }
    
   /* // Did ball collide with right wall
    if (_vecBallPos.x >= 1024 - _THICKNESS && _vecBallVelocity.x > 0.0f){
        _vecBallVelocity.x *= -1;
    }*/
}

void Game::_generateOutput(){
    // Set background to blue
    SDL_SetRenderDrawColor(_pRenderer, 0, 0, 255, 255);
    
    // Clear the back buffer to be ready to draw.
    SDL_RenderClear(_pRenderer);
    
    // Do all the drawing of walls, paddle, ball ...
    // Draw top wall
    SDL_Rect wall{0, 0, 1024, _THICKNESS};
    SDL_SetRenderDrawColor(_pRenderer, 0, 0, 255, 255);
    SDL_RenderFillRect(_pRenderer, &wall);
    
    // Draw bottom wall
    wall.y = 768 - _THICKNESS;
    SDL_RenderFillRect(_pRenderer, &wall);
    
   /* // Draw right wall
    wall.x = 1024 - _THICKNESS;
    wall.y = 0;
    wall.w = _THICKNESS;
    wall.h = 1024;
    SDL_RenderFillRect(_pRenderer, &wall);
   */
    // Draw paddle
    SDL_SetRenderDrawColor(_pRenderer, 255, 255, 255, 255);
    SDL_Rect paddle{(int)_vecPaddlePos.x, (int)_vecPaddlePos.y, _THICKNESS, 100};
    SDL_RenderFillRect(_pRenderer, &paddle);
    
    // Draw paddle2
    SDL_SetRenderDrawColor(_pRenderer, 255, 255, 255, 255);
    SDL_Rect paddle2{(int)_vecPaddlePos2.x, (int)_vecPaddlePos2.y, _THICKNESS, 100};
    SDL_RenderFillRect(_pRenderer, &paddle2);
    
    // Draw ball
    SDL_Rect ball{(int)_vecBallPos.x, (int)_vecBallPos.y, _THICKNESS, _THICKNESS};
    SDL_RenderFillRect(_pRenderer, &ball);
    
    // Swap the front and back buffers
    SDL_RenderPresent(_pRenderer);
}
