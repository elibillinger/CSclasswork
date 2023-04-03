//
//  main.cpp
//  Pathfinding
//
//  Created by Eli Billinger on 3/14/22.
//

#include <stdio.h>
#include "Game.hpp"

int main(int argc, char** argv){
    //Start our game
    Game game;
    
    bool bSuccess = game.Initialize();
    if (bSuccess){
        game.RunLoop();
    }
    game.Shutdown();
    return 0;
}

