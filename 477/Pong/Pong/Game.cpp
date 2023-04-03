#include "Game.h"

Game::Game(){
    _pWindow = nullptr;
    _pRenderer = nullptr;
    _bIsRunning = true;
    _nTickCount = 0;
    _nPaddleDir = 0;
    _nPaddle2Dir = 0;
}

Game::~Game(){
}

//Initialize the game
bool Game::Initialize(){
    //Initialize SDL
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if(sdlResult != 0) {
        SDL_Log("Unable to Initialize SDL: %s", SDL_GetError());
        return false;
    }
    
    //Create the window
    _pWindow = SDL_CreateWindow("Pong", 100, 100, 1024, 768, 0);
     
    if(!_pWindow){
        SDL_Log("Failed ot create window: %s", SDL_GetError());
        return false;
    }
    
    //Create Renderer
    _pRenderer = SDL_CreateRenderer(_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(!_pRenderer){
        SDL_Log("Failed ot create renderer: %s", SDL_GetError());
        return false;
    }
    
    //Initialize paddle and ball locations
    _vecPaddlePos.x = 10.0f;
    _vecPaddlePos.y = 768.0f / 2.0f;
    _vecPaddle2Pos.x = 1000.0f;
    _vecPaddle2Pos.y = 768.0f / 2.0f;
    _vecBallPos.x = 1024.0f / 2.0f;
    _vecBallPos.y = 768.0f / 2.0f;
    _vecBallVelocity.x = -200.0f;
    _vecBallVelocity.y = 235.0f;
    
    
    return true;
}

//Run the overall game loop
void Game::RunLoop(){
    while(_bIsRunning){
        _processInput();
        _updateGame();
        _generateOutput();
    }
}

//Shutdown the game
void Game::Shutdown(){
    //Cleanup SDL
    SDL_DestroyRenderer(_pRenderer);
    SDL_DestroyWindow(_pWindow);
    SDL_Quit();
}

void Game::_processInput(){
    // Poll for events in window
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_QUIT:
                _bIsRunning = false;
                break;
        }
    }
    
    //Get the entire state of the keyboard in an unsigned integer array
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if(state[SDL_SCANCODE_ESCAPE]){
        _bIsRunning = false;
    }
    
    //Move paddle 1 up with w and down with s keys
    if(state[SDL_SCANCODE_W] && _movePaddle1Up){
        _nPaddleDir = -1;
    } else if(state[SDL_SCANCODE_S] && _movePaddle1Down){
        _nPaddleDir = 1;
    } else {
        _nPaddleDir = 0;
    }
    
    //Move paddle 2 up with i and down with k keys
    if(state[SDL_SCANCODE_I] && _movePaddle2Up){
        _nPaddle2Dir = -1;
    } else if(state[SDL_SCANCODE_K] && _movePaddle2Down){
        _nPaddle2Dir = 1;
    } else {
        _nPaddle2Dir = 0;
    }
}

void Game::_updateGame(){
    
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), _nTickCount + 16));
    
    //Delta time is the difference in ticks from the last frame
    // to this frame converted to seconds
    float deltaTime = (SDL_GetTicks() - _nTickCount) / 1000.0f;
    
    _nTickCount = SDL_GetTicks();
    
    //Update paddle direction based on direction
    if(_nPaddleDir != 0){
        _vecPaddlePos.y += _nPaddleDir * 300.0f * deltaTime;
        
        //check to see if paddle 1 has reached bottom of screen
        if(_vecPaddlePos.y >= (668)){
            _nPaddleDir = 0;
            _movePaddle1Down = false;
        } else {
            _movePaddle1Down = true;
        }
        
        //check to see if paddle 1 has reached top of screen
        if(_vecPaddlePos.y <= 0){
            _nPaddleDir = 0;
            _movePaddle1Up = false;
        } else {
            _movePaddle1Up = true;
        }
    }
    
    //Update paddle direction based on direction
    if(_nPaddle2Dir != 0){
        _vecPaddle2Pos.y += _nPaddle2Dir * 300.0f * deltaTime;
        
        //check to see if paddle 1 has reached bottom of screen
        if(_vecPaddle2Pos.y >= (668)){
            _nPaddle2Dir = 0;
            _movePaddle2Down = false;
        } else {
            _movePaddle2Down = true;
        }
        
        //check to see if paddle 1 has reached top of screen
        if(_vecPaddle2Pos.y <= 0){
            _nPaddle2Dir = 0;
            _movePaddle2Up = false;
        } else {
            _movePaddle2Up = true;
        }
    }
    
    //update the ball based on its velocity and deltatime
    _vecBallPos.x += _vecBallVelocity.x * deltaTime;
    _vecBallPos.y += _vecBallVelocity.y * deltaTime;
    
    // collision with the paddle
    float diff = _vecPaddlePos.y - _vecBallPos.y;
    diff = (diff > 0.0f) ? diff : -diff;
    if(diff <= 100.0f  && _vecBallPos.x <= 25 && _vecBallPos.x >= 20 && _vecBallVelocity.x < 0) {
        _vecBallVelocity.x *= -1;
    }
    
    // collision with the paddle 2
    float diff2 = _vecPaddle2Pos.y - _vecBallPos.y;
    diff = (diff2 > 0.0f) ? diff2 : -diff2;
    if(diff2 <= 100.0f  && _vecBallPos.x <= 1000 && _vecBallPos.x >= 990 && _vecBallVelocity.x > 0) {
        _vecBallVelocity.x *= -1;
    }
    
    
    //Did ball collide with bottom wall
    if(_vecBallPos.y >= (768 - _THICKNESS) && _vecBallVelocity.y > 0.0f){
        _vecBallVelocity.y *= -1;
    }
    //Did ball collide with top wall
    if(_vecBallPos.y <= (_THICKNESS) && _vecBallVelocity.y < 0.0f){
        _vecBallVelocity.y *= -1;
    }
//    // Did ball collide with right wall
//    if(_vecBallPos.x >= (1024 - _THICKNESS) && _vecBallVelocity.x > 0.0f){
//        _vecBallVelocity.x *= -1;
//    }
}

void Game::_generateOutput(){
    //Set background to blue
    SDL_SetRenderDrawColor(_pRenderer, 0, 0, 255, 255);
    
    // Clear the back buffer to be ready to draw
    SDL_RenderClear(_pRenderer);
    
    // Do all drawings of walls, paddle, ball...
    // Draw top wall
    SDL_Rect wall{0,0,1024,_THICKNESS};
    SDL_RenderFillRect(_pRenderer, &wall);
    
    //Draw bottom wall
    wall.y = 768 - _THICKNESS;
    SDL_RenderFillRect(_pRenderer, &wall);
    
//    //Draw right wall
//    wall.x = 1024 - _THICKNESS;
//    wall.y = 0;
//    wall.w = _THICKNESS;
//    wall.h = 1024;
//    SDL_RenderFillRect(_pRenderer, &wall);
    
    //Draw paddle 1
    SDL_SetRenderDrawColor(_pRenderer, 255, 255, 255, 255);
    SDL_Rect paddle{(int)_vecPaddlePos.x,(int)_vecPaddlePos.y,_THICKNESS, 100};
    SDL_RenderFillRect(_pRenderer, &paddle);
    
    //Draw paddle 2
    SDL_SetRenderDrawColor(_pRenderer, 255, 255, 255, 255);
    SDL_Rect paddle2{(int)_vecPaddle2Pos.x,(int)_vecPaddle2Pos.y,_THICKNESS, 100};
    SDL_RenderFillRect(_pRenderer, &paddle2);
    
    //Draw ball
    SDL_Rect ball{(int)_vecBallPos.x,(int)_vecBallPos.y,_THICKNESS,_THICKNESS};
    SDL_RenderFillRect(_pRenderer, &ball);
    
    //Swap the front and back buffers
    SDL_RenderPresent(_pRenderer);
}
