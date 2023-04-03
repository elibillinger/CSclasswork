//
//  main.cpp
//  Pong
//
//  Created by Eli Billinger on 3/14/22.
//

#include <iostream>
#include "Game.h"

int main(int argc, const char * argv[]) {
    //Start our game
    Game game;
    
    bool bSuccess = game.Initialize();
    if(bSuccess){
        game.RunLoop();
    }
    
    game.Shutdown();
    return 0;
}
