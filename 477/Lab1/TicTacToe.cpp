//
// Created by Kathleen Kelly on 1/3/22.
//

#include "TicTacToe.h"
#include <iostream>
using namespace std;

TicTacToe::TicTacToe() {
    _initializeGame();
    _currentTurn = 1;
    for (int i = 0; i < GRID_SIZE; i++) {
        _gameGrid[i] = ' ';
    }
}

void TicTacToe::printGame() {
    cout << "+---+---+---+" << endl;
    for (int i = 0; i < GRID_SIZE; i++) {
        cout << "| " << _gameGrid[i] << " ";
        if ((i+1) % 3 == 0 && i != 0) {
            cout << "|" << endl;
            cout << "+---+---+---+" << endl;
        }
    }
}

int TicTacToe::getCurrentPlayer() const {
    return _currentTurn;
}

bool TicTacToe::playerTakeTurn(int space) {
    // Validate space first.
    // If space is invalid or already full,
    // return false.
    if (space < 0 || space >= GRID_SIZE) {
        return false;
    } else if (!_isEmpty(_gameGrid[space])) {
        return false;
    }

    // Determine whose turn it is.
    bool isP2 = _currentTurn % 2 == 0;
    if (isP2) {
        _gameGrid[space] = 'O';
    } else {
        _gameGrid[space] = 'X';
    }

    _currentTurn += 1;

    return true;
}

bool TicTacToe::isGridFull() {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (_gameGrid[i] == ' ') {
            return false;
        }
    }
    return true;
}

int TicTacToe::checkWinner() {
    bool isP2 = _currentTurn % 2 == 0;
    bool gameWon = _checkWon();
    if (gameWon && isP2) {
        return PLAYER_2;
    } else if (gameWon && !isP2) {
        return PLAYER_1;
    } else {
        return 0;
    }
}

bool TicTacToe::_checkWon() {
    if (_rowWon()) {
        return true;
    } else if (_columnWon()) {
        return true;
    } else if (_diagonalWon()) {
        return true;
    }

    return false;
}


void TicTacToe::_initializeGame() {
    for (int i = 0; i < GRID_SIZE; i++) {
        _gameGrid[i] = ' ';
    }
}

bool TicTacToe::_isEmpty(char choice) {
    if (choice == ' ') {
        return true;
    }
    return false;
}

bool TicTacToe::_rowWon() {
    for (int i = 0; i < GRID_SIZE; i++) {
        char firstInRow = _gameGrid[i];
        char secondInRow = _gameGrid[i+1];
        char thirdInRow = _gameGrid[i+2];

        if (!_isEmpty(firstInRow) && !_isEmpty(secondInRow) && !_isEmpty(thirdInRow)) {
            if (firstInRow == secondInRow && firstInRow == thirdInRow) {
                return true;
            }
        }
    }

    return false;
}

bool TicTacToe::_columnWon() {
    for (int i = 0; i < 3; i++) {
        char firstInColumn = _gameGrid[i];
        char secondInColumn = _gameGrid[i+3];
        char thirdInColumn = _gameGrid[i+6];

        if (!_isEmpty(firstInColumn) && !_isEmpty(secondInColumn) && !_isEmpty(thirdInColumn)) {
            if (firstInColumn == secondInColumn && firstInColumn == thirdInColumn) {
                return true;
            }
        }
    }

    return false;
}

bool TicTacToe::_diagonalWon() {
    char center = _gameGrid[4];
    bool diag1 = false;
    if (!_isEmpty(center) && !_isEmpty(_gameGrid[0]) && !_isEmpty(_gameGrid[8])) {
        diag1 = (center == _gameGrid[0] && center == _gameGrid[8]);
    }

    bool diag2 = false;
    if (!_isEmpty(center) && !_isEmpty(_gameGrid[2]) && !_isEmpty(_gameGrid[6])) {
        diag2 =  (center == _gameGrid[2] && center == _gameGrid[6]);
    }

    return diag1 || diag2;
}
