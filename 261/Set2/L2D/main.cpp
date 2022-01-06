/* CSCI 261 Lab 2D: RPS And The Winner Is
 *
 * Author: Eli Billinger
 *
 * Updating Lab 2C to determine a winner
 * Changed for extra credit part
 * k for spock and l for lizard
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // generate random number
    srand(time(0));
    rand();
    int randNum = rand() % 5;
    string compChoice;

    // get user choice
    string playerChoice;
    cout << "Welcome one and all to a round of Rock, Paper, Scissors, Lizard, Spock! (Enter P for Paper, R for Rock, L for Lizard, K for Spock or S)" << endl << "Player one: ";
    cin >> playerChoice ;

    // change user entered letter to action and output
    if(playerChoice == "R" || playerChoice == "r"){
        playerChoice = "Rock" ;
    } else if(playerChoice == "P" || playerChoice == "p"){
        playerChoice = "Paper";
    } else if(playerChoice == "S" || playerChoice == "s"){
        playerChoice = "Scissors";
    } else if(playerChoice == "L" || playerChoice == "l") {
        playerChoice = "Lizard";
    }
    else if(playerChoice == "K" || playerChoice == "k") {
        playerChoice = "Spock";
    }
    cout << endl << "Player choose " << playerChoice << endl;

    // change random Number to action and output
    if(randNum==0){
        compChoice = "Rock" ;
    } else if(randNum==1){
        compChoice = "Paper";
    }else if(randNum==2) {
        compChoice = "Lizard";
    }else if(randNum==3) {
        compChoice = "Spock";
    }else{
        compChoice = "Scissors";
    }
    cout << "Computer choose " << compChoice << endl;

    // determine winner
    if( compChoice != playerChoice){
        if((compChoice == "Rock" || playerChoice == "Rock") && (compChoice == "Scissors" || playerChoice == "Scissors")){
            cout << "Rock crushes Scissors" << endl;
            if(compChoice == "Rock"){
                cout << "Computer Wins!" << endl;
            } else {
                cout << "Player Wins!" << endl;
            }
        } else if((compChoice == "Paper" || playerChoice == "Paper") && (compChoice == "Scissors" || playerChoice == "Scissors")){
            cout << "Scissors cuts Paper" << endl;
            if(compChoice == "Scissors"){
                cout << "Computer Wins!" << endl;
            } else {
                cout << "Player Wins!" << endl;
            }
        } else if((compChoice == "Rock" || playerChoice == "Rock") && (compChoice == "Paper" || playerChoice == "Paper")){
            cout << "Paper covers Rock" << endl;
            if(compChoice == "Paper"){
                cout << "Computer Wins!" << endl;
            } else {
                cout << "Player Wins!" << endl;
            }
        } else if ((compChoice == "Rock" || playerChoice == "Rock") && (compChoice == "Lizard" || playerChoice == "Lizard")) {
            cout << "Rock crushes Lizard" << endl;
            if (compChoice == "Rock") {
                cout << "Computer Wins!" << endl;
            } else {
                cout << "PLayer Wins!" << endl;
            }
        } else if ((compChoice == "Rock" || playerChoice == "Rock") && (compChoice == "Spock" || playerChoice == "Spock")){
            cout << "Spock vapourises Rock" << endl;
            if (compChoice == "Spock") {
                cout << "Computer Wins!" << endl;
            } else {
                cout << "PLayer Wins!" << endl;
            }
        } else if ((compChoice == "Paper" || playerChoice == "Paper") && (compChoice == "Lizard" || playerChoice == "Lizard")) {
            cout << "Lizard eats Paper" << endl;
            if (compChoice == "Lizard") {
                cout << "Computer Wins!" << endl;
            } else {
                cout << "PLayer Wins!" << endl;
            }
        } else if ((compChoice == "Paper" || playerChoice == "Paper") && (compChoice == "Spock" || playerChoice == "Spock")){
            cout << "Paper disproves Spock" << endl;
            if (compChoice == "Paper") {
                cout << "Computer Wins!" << endl;
            } else {
                cout << "PLayer Wins!" << endl;
            }
        } else if ((compChoice == "Scissors" || playerChoice == "Scissors") && (compChoice == "Lizard" || playerChoice == "Lizard")) {
            cout << "Scissors decapitates Lizard" << endl;
            if (compChoice == "Scissors") {
                cout << "Computer Wins!" << endl;
            } else {
                cout << "PLayer Wins!" << endl;
            }
        } else if ((compChoice == "Scissors" || playerChoice == "Scissors") && (compChoice == "Spock" || playerChoice == "Spock")){
            cout << "Spock smashes Scissors" << endl;
            if (compChoice == "Spock") {
                cout << "Computer Wins!" << endl;
            } else {
                cout << "PLayer Wins!" << endl;
            }
        } else if ((compChoice == "Lizard" || playerChoice == "Lizard") && (compChoice == "Spock" || playerChoice == "Spock")){
            cout << "Lizard poisons Spock" << endl;
            if (compChoice == "Lizard") {
                cout << "Computer Wins!" << endl;
            } else {
                cout << "PLayer Wins!" << endl;
            }
        }



    } else{
        cout << "The Computer and Player Tied!" << endl;
    }


    return 0;
}