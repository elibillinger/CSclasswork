//
// Created by Eli Billinger on 4/27/20.
//
#include <iostream>
#include<fstream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <random>
#include "classes.h"
using namespace std;
// creates the Inital table of hidden cards using hiddencards array
void Table::createTable() {
    int counter = 0;
    int rowCounter = 1;
    cout << "0 | A | B | C | D | E |" << endl;
    for (int i = 0; i < 20; i++){
        counter++;
        if(counter == 1 || counter == 6 || counter ==  11 || counter == 16){
            cout << rowCounter << " | ";
            rowCounter++;
        }
        cout << hiddenCards[i] << " | ";
        if(counter%5 == 0)
        cout << endl;
    }
}
// creates the card array by reading the file 'cards.txt'
void Table::createCardArray(){
        ifstream cardsList;
        cardsList.open("cards.txt");
        if(cardsList.fail()){
            cerr << "Error in Opening File" << endl;
        }
    for (int i = 0; i < 20; i++){
        char card;
        cardsList >> card;
        cards[i] = card;
    }
    // shuffles the card location to be different every game
    shuffle(&cards[0],&cards[19], std::mt19937(std::random_device()()));
    }
// outputs the table once the game starts
void Table::printTable() {
    int counter = 0;
    int rowCounter = 1;
    cout << "\n0 | A | B | C | D | E |" << endl;
    for (int i = 0; i < 20; i++){
        counter++;
        if(counter == 1 || counter == 6 || counter ==  11 || counter == 16){
            cout << rowCounter << " | ";
            rowCounter++;
        }
        cout << showHiddenCards[i] << " | ";
        if(counter%5 == 0)
            cout << endl;
    }
}
// changes the values in the showHidden cards array to their non-hidden values and changes them back if they dont match
void Table::updatedTable(int cardOne, int cardTwo) {
    showHiddenCards[cardOne] = cards[cardOne];
    showHiddenCards[cardTwo] = cards[cardTwo];
    printTable();
    if(cards[cardOne] != cards[cardTwo]){
        showHiddenCards[cardOne] = hiddenCards[cardOne];
        showHiddenCards[cardTwo] = hiddenCards[cardTwo];
        cout << "\nThe Cards Do Not Match" ;
        printTable();
    }
}
// checks to see if the game is won by comparing showHiddenCards array and cards array
void Table::checkWin() {
    if (equal(begin(showHiddenCards), end(showHiddenCards), begin(cards)))
        gameWon = true;
}
// prints out the game instructions
void Matching::instructions() const {
    cout << "Welcome to Card Matching Game" << endl;
    cout << "In order to beat the game you must match every pair of cards" << endl;
    cout << "The game will prompt you for the coordinate of the cards you want to pick" << endl;
    cout << "The coordinates should be entered as the letter than number e.i.(A4)" << endl;
    cout << "If the cards are the same the symbols on them will stay showing" << endl;
    cout << "If they are not they will flip over and you wont be able to see them unless they are picked again" << endl;
    cout << "Enter Y if you understand and are ready to play" << endl;
}
// starts teh game by calling other functions and it does this until the game has been won
void Matching::startGame() {
    turnCounter = 0;
    table.createCardArray();
    table.createTable();
    cin.ignore();
    // checks if game has won
    do {
        getCoords();
        showCards();
        table.checkWin();
    } while (table.gameWon == false);
    cout << "Congratulations You Won" << endl;
    cout << "It took you " << turnCounter << " turns to win" << endl;
    restartGame();
}

// asks the user for the card coordinates one at a time
void Matching::getCoords() {
    cout << "Enter the coordinate of the first card: ";
    coordOne = " ";
    cin.clear();
    getline(cin,coordOne);
   cout << "\nEnter the coordinate of the secound card: ";
   coordTwo = " ";
    cin.clear();
    getline(cin,coordTwo);
}
// converts the coordinates to its place in the array
int Matching::convertCoords(string coordinate) {
    for_each(coordinate.begin(), coordinate.end(), [](char & c){
        c = ::toupper(c);
    });
    int tablePoint = ((int)coordinate[0])-64;
    int tablePoint2 = coordinate[1]-'0';
    if(tablePoint > 5){
        cout << "Invalid Coordinates  Column given is not available" << endl;
        getCoords();
    }
    if(tablePoint2 == 1 ){
        return tablePoint-1;
    } else if(tablePoint2 == 2){
        return tablePoint+4;
    } else if(tablePoint2 == 3){
        return tablePoint+9;
    } else if(tablePoint2 == 4){
        return tablePoint+14;
    }
}
// checks if coodinates are valid then converts them and outputs new table
void Matching::showCards() {
    turnCounter += 1;
    checkString(coordOne);
    checkString(coordTwo);
    int cardOne = convertCoords(coordOne);
    int cardTwo = convertCoords(coordTwo);
    table.updatedTable(cardOne,cardTwo);
}

// checks to see if coordinates are valid
void Matching::checkString(string coordinate){
    std::for_each(coordinate.begin(), coordinate.end(), [](char & c){
        c = toupper(c);
    });
    if(!isdigit(coordinate[1])){
        cout << "Invalid Coordinates Non Number Given For Row" << endl;
        getCoords();
    }
    if(!isalpha(coordinate[0])){
        cout << "Invalid Coordinates Non Letter Given For Column" << endl;
        getCoords();
    }
    int tablePoint = ((int)coordinate[0])-64;
    int tablePoint2 = coordinate[1]-'0';
    // checks column value (A-E)
    if(tablePoint > 5){
        cout << "Invalid Coordinates  Column given is not available" << endl;
        getCoords();
    }
    // checks row value (1-4)
    if(tablePoint2 > 4 && tablePoint2 > 0){
        cout << "Invalid Coordinates  ROW given is not available" << endl;
        getCoords();
    }
}

void Matching::restartGame() {
    char choice;
    cout << "Would you like to play again? (Y or N)" << endl;
    cin >> choice;
    if(choice == 'Y' || choice == 'y'){
        startGame();
    }
}