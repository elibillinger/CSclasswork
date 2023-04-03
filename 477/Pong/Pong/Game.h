#ifndef Game_h
#define Game_h

#include <stdio.h>
#include <SDL2/SDL.h>

class Game
{
public:
    struct Vector2 {
        float x;
        float y;
    };
    
    Game();
    ~Game();
    
    //Initialize the game
    bool Initialize();
    
    //Run the game loop until the game is over
    void RunLoop();
    
    //Shutdown the game
    void Shutdown();
    
private:
    void _processInput();
    
    void _updateGame();
    
    void _generateOutput();
    
    SDL_Window* _pWindow;
    SDL_Renderer* _pRenderer;
    
    // Is the game still running
    bool _bIsRunning;
    
    //Wall thickness
    const int _THICKNESS = 15;
    
    //Paddle and ball locations
    Vector2 _vecPaddlePos;
    Vector2 _vecPaddle2Pos;
    Vector2 _vecBallPos;
    Vector2 _vecBallVelocity;
    int _nPaddleDir;
    int _nPaddle2Dir;
    
    //Number of ticks since the start of the game
    Uint32 _nTickCount;
    
    //keep track if paddel can move down or up any more
    bool _movePaddle1Up = true;
    bool _movePaddle1Down = true;
    bool _movePaddle2Up = true;
    bool _movePaddle2Down = true;
};

#endif /* Game_h */

