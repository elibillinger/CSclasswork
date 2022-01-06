//
// USING 1 SKIP DAY 1 REMAINING
//

#ifndef A7_ELI_BILLINGER_H
#define A7_ELI_BILLINGER_H



class Minesweeper{
public:
    Minesweeper();
    void introduction() const;
    void startGame();

private:
    int gameWon;
    std::string prize;
    char gameBoardCovered[10][9] = {{'A','B','C','D','E','F','G','H','I'},{'-','-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-','-'}};
    char gameBoardSolution[10][9] = {{'A','B','C','D','E','F','G','H','I'},{'1','2','2','1',' ',' ',' ','1','-'},{'1','-','-','1',' ','1','1','2','1'},{'1','2','2','1',' ','1','-','1',' '},{' ',' ','1','1','1','1','1','2','1'},{' ',' ','1','-','1',' ',' ','1','-'},{'1','1','1','1','2','1','1','1','1'},{'-','1',' ',' ','2','-','2',' ',' '},{'1','1',' ','1','3','-','2',' ',' '},{' ',' ',' ','1','-','2','1',' ',' '}};
    void createGrid();
    void getPosition();
    void getPrize();
    void checkBomb(std::string userPosition);
    void changeGrid(char uncoveredItem, std::string userPosition);
    void checkSpace(std::string userPosition);
    void checkWin();
    void restartGame();
};

#endif //A7_ELI_BILLINGER_H
