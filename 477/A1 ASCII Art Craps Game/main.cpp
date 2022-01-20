//
// Created by Eli Billinger on 1/14/22.
//

#include <iostream>
#include "Dice.h"
int main() {
    char choice;
    //loop until user does not want to play anymore
    while(true) {
        bool validFirst = true;
        Dice game;
        int roll = 0;
        std::cout << "You rolled..." << std::endl;
        game.RollDice();
        std::cout << "Your point is ... " << game.Point << std::endl;
        // end current game if 2,3,12 are rolled - losing rolls
        if (game.Point == 2 || game.Point == 3 || game.Point == 12) {
            std::cout << "YOU LOST  GAME OVER\n";
            validFirst = false;
        }
        // end current game if 7,11 are rolled - winning rolls
        if (game.Point == 7 || game.Point == 11) {
            std::cout << "CONGRATULATIONS ... YOU WIN!\n ";
            validFirst = false;
        }
        // roll the dice again if the point roll is not  matched or the game does not end on first roll
        while (roll != game.Point && validFirst) {
            std::cout << "You rolled..." << std::endl;
            game.RollDice();
            roll = game.DiceRoll;
            if (roll == 7) {
                std::cout << "YOU LOST  GAME OVER\n";
                break;
            } else if (roll == game.Point) {
                std::cout << "CONGRATULATIONS ... YOU WIN! \n";
                break;
            } else {
                std::cout << "Your point is ... " << game.Point << std::endl;
            }
        }
        //check if player wants to play again by using characters of y and n
        std::cout << "Play Again? (Type Y for Yes and N for No)";
        std::cin >> choice;
        if(tolower(choice) != 'y' && tolower(choice) != 'n'){
            while (tolower(choice) != 'y' || 'n') {
                std::cout << "Invalid Character enter Y or N";
                std::cin >> choice;
                if(tolower(choice) == 'y' || tolower(choice) == 'n'){
                    break;
                }
            }
        }
        if(tolower(choice) == 'n'){
            break;
        }
    }

    return 0;
}
