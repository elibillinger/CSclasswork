/* CSCI 261 Lab 2C: RPS State Your Choice
 *
 * Author: Eli Billinger
 *
 * Updating Lab 2B to show the correct actions instead of numbers (0,1,2) and letters (s,p,r)
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // generate random number
    srand(time(0));
    rand();
    int randNum = rand() % 3;
    string compChoice;

    // get user choice
    string playerChoice;
    cout << "Welcome one and all to a round of Rock, Paper, Scissors! (Enter P, R or S)" << endl << "Player one: ";
    cin >> playerChoice ;

    // change user entered letter to action and output
    if(playerChoice == "R" || playerChoice == "r"){
        playerChoice = "Rock" ;
    } else if(playerChoice == "P" || playerChoice == "p"){
        playerChoice = "Paper";
    } else if(playerChoice == "S" || playerChoice == "s"){
        playerChoice = "Scissors";
    }
    cout << endl << "Player choose " << playerChoice << endl;

    // change random Number to action and output
    if(randNum==0){
         compChoice = "Rock" ;
    } else if(randNum==1){
        compChoice = "Paper";
    } else {
        compChoice = "Scissors";
    }
    cout << "Computer choose " << compChoice << endl;

    return 0;
}