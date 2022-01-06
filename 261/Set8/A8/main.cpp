/* CSCI 261 A8 Share Magic Item
 *
 * Author: Eli Billinger
 * NO L8A
 * DID NOT SHARE MAGIC ITEM WITH OTHERS AND DID NOT GET ANYONE ELSE'S MAGIC ITEM
 * Created Minesweeper for magic item
 */
#include <iostream>
#include "eli_billinger.h"
using namespace std;

int main() {
    int choice;
    cout << "Enter 1 to play Minesweeper";
    cin >> choice;
    if(choice == 1) {
        Minesweeper game;
        game.introduction();
        game.startGame();
    }
    return 0;
}
