//
// Created by Eli Billinger on 4/27/20.
//

#ifndef FINAL_PROJECT_CLASSES_H
#define FINAL_PROJECT_CLASSES_H

#include <iostream>
#include <string>
using namespace std;
class Table{
public:
    bool gameWon = false;
    void createTable();
    void createCardArray();
    void updatedTable(int cardOne, int cardTwo);
    void checkWin();
private:
    char cards[20]; // array with cards
    char hiddenCards[20] = {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'};
    char showHiddenCards[20] = {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'}; // array that can be changed based on user guesses
    void printTable();

};

class Matching{
public:
    Table table;
    void instructions() const;
    void startGame();
private:
    int turnCounter;
    string coordOne;
    string coordTwo;
    void getCoords();
    int convertCoords(string coordinate);
    void showCards();
    void checkString(string coordinate);
    void restartGame();

};
#endif //FINAL_PROJECT_CLASSES_H
