//
//  Game.hpp
//  Pathfinding
//
//  Created by Eli Billinger on 3/14/22.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
//Generic Game Class
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
    
    //Run game loop until game is over
    void RunLoop();
    
    //Shutdown the game
    void Shutdown();
    
private:
    void _processInput();
    
    void _updateGame();
    
    void _generateOutput();

    //SDL Window and renderer
    SDL_Window* _pWindow;
    SDL_Renderer* _pRenderer;
    
    //Is the game still running
    bool _bIsRunning;
    
    // Wall thickness
    const int _THICKNESS = 15;
    
    // Paddle and ball locations
    Vector2 _vecPaddlePos;
    Vector2 _vecBallPos;
    Vector2 _vecBallVelocity;
    int _nPaddleDir;
    Vector2 _vecPaddlePos2;
    int _nPaddleDir2;
    
    // Number of ticks since start of game
    Uint32 _nTickCount;
    
};
#endif /* Game_hpp */
