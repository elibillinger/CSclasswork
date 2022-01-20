#include <iostream>
#include "TicTacToe.h"
using namespace std;

int main() {
    TicTacToe game;

    cout << "Tic Tac Toe" << endl << endl;
    game.printGame();
    cout << endl;

    while (!game.isGridFull()) {
        int slotChoice;

        // Determine whose turn it is.
        bool isP2 = game.getCurrentPlayer() % 2 == 0;
        if (isP2) {
            cout << "Player 2 turn...select a slot 0-8: " << endl;
        } else {
            cout << "Player 1 turn...select a slot 0-8: " << endl;
        }
        cin >> slotChoice;

        // Validation loop.
        while (!game.playerTakeTurn(slotChoice)) {
            cout << "Slot occupied or invalid slot, please select another slot: ";
            cin >> slotChoice;
        }

        game.printGame();
        cout << endl;

        // Check for winner.
        int winner = game.checkWinner();
        if (winner == TicTacToe::PLAYER_2) {
            cout << "Player 2 wins!" << endl;
            break;
        } else if (winner == TicTacToe::PLAYER_1) {
            cout << "Player 1 wins!" << endl;
            break;
        }
    }

    if (!game.checkWinner()) {
        cout << "Draw!" << endl;
    }

    return 0;
}


