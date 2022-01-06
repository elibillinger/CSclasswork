//
// Minesweeper
//

#include <iostream>
#include <string>
#include "eli_billinger.h"
using namespace std;

void Minesweeper::introduction() const  {
    cout << "Welcome to Mindsweeper" << endl;
    cout << "Enter a Coordinate to pick a space giving a capital letter (A-I) than a number (1-9) like A6" << endl;
    cout << "If you choose a space with a bomb the game will end and you will get the choice to restart" << endl;
    cout << "If you clear all teh spaces EXCEPT for the bomb you win" << endl;
}

Minesweeper::Minesweeper() {
    gameWon = 0;
    prize = "infinte bombs";
}
//give prize
void Minesweeper::getPrize() {
    cout << "Congratulations you Won" << endl;
    cout << "Your prize is " << prize;
    exit(0);
}
// print the grid/game board
void Minesweeper::createGrid() {
    char gameBoardUncovered[10][9] = {{'A','B','C','D','E','F','G','H','I'},{'1','2','2','1',' ',' ',' ','1','B'},{'1','B','B','1',' ','1','1','2','1'},{'1','2','2','1',' ','1','B','1',' '},{' ',' ','1','1','1','1','1','2','1'},{' ',' ','1','B','1',' ',' ','1','B'},{'1','1','1','1','2','1','1','1','1'},{'B','1',' ',' ','2','B','2',' ',' '},{'1','1',' ','1','3','B','2',' ',' '},{' ',' ',' ','1','B','2','1',' ',' '}};
    for (int i = 0; i < 10; i++){
        cout << i << "| ";
        for (int j = 0; j< 9; j++){
            cout << gameBoardCovered[i][j] << " | ";
        }
        cout << endl;
    }
    //checkWin();
}
// start the game
void Minesweeper::startGame() {
    char choice;
    cout << "If you are ready to start enter Y or N" << endl;
    cin >> choice;
    if(choice == 'Y'){
        createGrid();
        getPosition();
    }
}
// ask user for what location they want to check
void Minesweeper::getPosition() {
    string userPosition;
    cout << "Enter Position of Your Choice:";
    cin.clear();
    getline(cin, userPosition);
    cout << userPosition << endl;
    checkBomb(userPosition);
}
// check position chosen for bomb or space
void Minesweeper::checkBomb(string userPosition) {
    char gameBoardUncovered[10][9] = {{'A','B','C','D','E','F','G','H','I'},{'1','2','2','1',' ',' ',' ','1','B'},{'1','B','B','1',' ','1','1','2','1'},{'1','2','2','1',' ','1','B','1',' '},{' ',' ','1','1','1','1','1','2','1'},{' ',' ','1','B','1',' ',' ','1','B'},{'1','1','1','1','2','1','1','1','1'},{'B','1',' ',' ','2','B','2',' ',' '},{'1','1',' ','1','3','B','2',' ',' '},{' ',' ',' ','1','B','2','1',' ',' '}};
    int coordOne = ((int)userPosition[0])-64;
    int coordTwo = userPosition[1]-'0';
    if(gameBoardUncovered[coordTwo][coordOne-1] == 'B'){
        changeGrid('B',userPosition);
        createGrid();
        cout << "GameOver Pressed a Bomb" << endl;
        restartGame();
    } else if(gameBoardUncovered[coordTwo][coordOne-1] == ' '){
        checkSpace(userPosition);
        createGrid();
        checkWin();
        if( gameWon != 1)
        getPosition();
    }else{
        changeGrid(gameBoardUncovered[coordTwo][coordOne-1],userPosition);
        createGrid();
        checkWin();
        if( gameWon != 1)
        getPosition();
    }
}
// set the result for the point chosen in the array
void Minesweeper::changeGrid(char uncoveredItem, string userPosition ) {
    int coordOne = ((int)userPosition[0])-64;
    int coordTwo = userPosition[1]-'0';
    gameBoardCovered[coordTwo][coordOne-1] = uncoveredItem;
}
// gives option to restart the game if failed
void Minesweeper::restartGame() {
    char restart;
    cout << "Would you like to try again? (Y or N)";
    cin >> restart;
    if(restart == 'Y'){
        for(int i = 1; i < 10; i++){
            for(int j = 0; j< 9; j++){
                gameBoardCovered[i][j] = '-';
            }
        }
        createGrid();
        getPosition();
    }
}
// check if only bombs remaining for win
void Minesweeper::checkWin(){
    gameWon = 1;
    int counter = 0;
    for(int i = 1; i < 10; i++){
        for(int j = 0; j< 9; j++){
            if(gameBoardCovered[i][j] == gameBoardSolution[i][j]){
                counter += 1;
            }
        }
    }
    if(counter == 81){
        getPrize();
    } else{
        getPosition();
    }
}

// hard coded what spaces to show for when an empty space is selected
void Minesweeper::checkSpace(string userPosition) {
    int coordOne = ((int)userPosition[0])-64;
    int coordTwo = userPosition[1]-'0';
    if((((coordOne == 5) && (coordTwo == 1|| coordTwo == 2 || coordTwo == 3))||(coordOne == 6 && coordTwo == 1)||(coordOne == 7 && coordTwo == 1))){
        gameBoardCovered[1][4] = ' ';
        gameBoardCovered[2][4] = ' ';
        gameBoardCovered[3][4] = ' ';
        gameBoardCovered[1][5] = ' ';
        gameBoardCovered[1][6] = ' ';
        gameBoardCovered[4][4] = '1';
        gameBoardCovered[1][3] = '1';
        gameBoardCovered[2][3] = '1';
        gameBoardCovered[3][3] = '1';
        gameBoardCovered[2][5] = '1';
        gameBoardCovered[3][5] = '1';
        gameBoardCovered[2][6] = '1';
        gameBoardCovered[1][7] = '1';
    } else if ((((coordOne == 3) && (coordTwo == 7|| coordTwo == 8 || coordTwo == 9))||(coordOne == 2 && coordTwo == 9)||(coordOne == 1 && coordTwo == 9)||(coordOne == 4 && coordTwo == 7))){
        gameBoardCovered[9][0] = ' ';
        gameBoardCovered[9][1] = ' ';
        gameBoardCovered[9][2] = ' ';
        gameBoardCovered[8][2] = ' ';
        gameBoardCovered[7][2] = ' ';
        gameBoardCovered[7][3] = ' ';
        gameBoardCovered[8][0] = '1';
        gameBoardCovered[8][1] = '1';
        gameBoardCovered[7][4] = '2';
        gameBoardCovered[7][1] = '1';
        gameBoardCovered[6][2] = '1';
        gameBoardCovered[6][3] = '1';
        gameBoardCovered[8][3] = '1';
        gameBoardCovered[9][3] = '1';
         } else if (((coordOne == 8) && (coordTwo == 7 || coordTwo == 8 || coordTwo == 9))||((coordOne == 9) && (coordTwo == 7 || coordTwo == 8 || coordTwo == 9))) {
        gameBoardCovered[9][7] = ' ';
        gameBoardCovered[9][8] = ' ';
        gameBoardCovered[8][7] = ' ';
        gameBoardCovered[8][8] = ' ';
        gameBoardCovered[7][7] = ' ';
        gameBoardCovered[7][8] = ' ';
        gameBoardCovered[9][6] = '1';
        gameBoardCovered[8][6] = '2';
        gameBoardCovered[7][6] = '2';
        gameBoardCovered[6][7] = '1';
        gameBoardCovered[6][8] = '1';
    } else if ((coordOne == 7 && coordTwo == 5)|| (coordOne == 6 && coordTwo == 5)){
        gameBoardCovered[4][5] = '1';
        gameBoardCovered[4][6] = '1';
        gameBoardCovered[5][4] = '1';
        gameBoardCovered[5][5] = ' ';
        gameBoardCovered[5][6] = ' ';
        gameBoardCovered[5][7] = '1';
        gameBoardCovered[6][5] = '1';
        gameBoardCovered[6][6] = '1';
    } else if((coordOne == 1 && (coordTwo == 5|| coordTwo == 4))|| (coordOne == 2 && (coordTwo == 5|| coordTwo == 4))){
        gameBoardCovered[4][0] = ' ';
        gameBoardCovered[4][1] = ' ';
        gameBoardCovered[5][0] = ' ';
        gameBoardCovered[5][1] = ' ';
        gameBoardCovered[3][1] = '2';
        gameBoardCovered[3][0] = '1';
        gameBoardCovered[6][1] = '1';
        gameBoardCovered[6][0] = '1';
        gameBoardCovered[4][2] = '1';
        gameBoardCovered[5][2] = '1';
    } else if(coordOne == 9 && coordTwo == 3){
        gameBoardCovered[2][8] = '1';
        gameBoardCovered[3][8] = ' ';
        gameBoardCovered[4][8] = '1';
        gameBoardCovered[3][7] = '1';
    }
    }