/* CSCI 261 Assignment 4: Guess the Number
*
* Author: Eli Billinger
*
* Guess the Number Game that make sure values inputed are numbers and not characters
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    //constants and variables
    const int TOO_CLOSE_DIFFERENCE = 5;
    const int TOO_HIGH_DIFFERENCE = 25;
    const int MIN_RANGE = 100;
    int numOne,numTwo,randNum,userGuess;
    int tries = 0;

    cout << "Welcome to Guess the Number!" << endl;
    // test if the first number is a integer
    while(true){
        cout << "\nEnter the lowest possible number: ";
        cin >> numOne;
        if( !cin.fail()){
            break;
        }
        cin.clear();
        char badChar = cin.get();
        while( badChar != '\n'){
            badChar = cin.get();
        }
    }
    //test if secound number is an integer and 100 more than the first number
    while(true) {
        cout << "\nEnter the highest possible number: ";
        cin >> numTwo;
        if(cin.fail()) {
            cin.clear();
            char badChar = cin.get();
            while( badChar != '\n'){
                badChar = cin.get();
            }
            continue;
        } else {
            if (numTwo < (MIN_RANGE+numOne)) { // make sure secound number is 100 more than first
                cout << "High number must be " << MIN_RANGE << " more than the lower number." << endl;
                continue;
            } else {
                break;
            }
        }
    }
    // generate random number within the range
    srand(time(0));
    rand();
    int range = numTwo-numOne;
    randNum = rand() % range + numOne;

    // determine if guess is valid and how close
    while (true){
        cout << "\nPick a number between " << numOne << " and " << numTwo << ": ";
        cin >> userGuess;
        if(cin.fail()) {
            cin.clear();
            char badChar = cin.get();
            while( badChar != '\n'){
                badChar = cin.get();
            }
            cout << "Please Guess a number." << endl;
            continue;
        } else {
            if (userGuess < numOne || userGuess > numTwo) { //make sure guess is in range
                cout << "Invalid Guess" << endl;
                continue;
            } else {
                tries += 1;
                if (userGuess != randNum) { // if guess is not correct
                    if(userGuess>randNum){ // if guess is higher than answer
                        cout << "Too high ";
                        if ((userGuess-randNum)<=TOO_CLOSE_DIFFERENCE){ // if within 5
                            cout << "Oooh you're close!" << endl;
                            continue;
                        } else if ((userGuess-randNum)>=TOO_HIGH_DIFFERENCE){ // if over 25 away
                            cout << "Not even close!" << endl;
                            continue;
                        }
                    } else { // if guess is lower than answer
                        cout << "Too Low ";
                        if (abs(userGuess-randNum)<=TOO_CLOSE_DIFFERENCE){ // if within 5
                            cout << "Oooh you're close!" << endl;
                            continue;
                        } else if(abs(userGuess-randNum)>=TOO_HIGH_DIFFERENCE){ // if over 25 away
                            cout << "Not even close!" << endl;
                            continue;
                        }
                    }
                }
                  if (userGuess == randNum){ // if correct than output amount of tries it took
                    cout << "That's right! You won the game in " << tries << " tries." << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
