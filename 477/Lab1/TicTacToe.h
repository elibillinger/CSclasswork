//
// Created by Kathleen Kelly on 1/3/22.
//

#ifndef TICTACTOE_TICTACTOE_H
#define TICTACTOE_TICTACTOE_H

class TicTacToe {
public:
    TicTacToe();
    void printGame();
    bool playerTakeTurn(int space);
    bool isGridFull();
    int checkWinner();
    int getCurrentPlayer() const;

    const static int PLAYER_1 = 1;
    const static int PLAYER_2 = 2;

private:
    const static int GRID_SIZE = 9;
    char _gameGrid[GRID_SIZE];
    int _currentTurn;

    void _initializeGame();
    bool _isEmpty(char choice);
    bool _checkWon();
    bool _rowWon();
    bool _columnWon();
    bool _diagonalWon();
};

#endif //TICTACTOE_TICTACTOE_H
