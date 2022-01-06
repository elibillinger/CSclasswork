/* CSCI 261 Final Project Memory Game
 *
 * Author: Eli Billinger
 *
 * Created A Memory Game Where You Match Cards
 */
#include <iostream>
#include "classes.h"
using namespace std;

int main() {
    // start game and give instructions
    Matching game;
    game.instructions();
    // make sure instructions were read
    char ready;
    cin >> ready;
    if(ready == 'Y' || ready == 'y'){
        game.startGame();
    } else {
        while (ready != 'Y' || ready != 'y') {
            cout << "PLEASE READ THE INSTRUCTIONS" << endl;
            game.instructions();
            cin >> ready;
            if (ready == 'Y' || ready == 'y') {
                break;
            }
        }
        game.startGame();
    }
    return 0;
}
