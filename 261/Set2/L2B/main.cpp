/* CSCI 261 Lab 2B: Rock Paper Scissors
 *
 * Author: Eli Billinger
 *
 * Creating computer's random number choice and getting user's choice
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    rand();

    char player_choice;

    cout << "Welcome one and all to a round of Rock, Paper, Scissors! (Enter P, R or S)" << endl << "Player one: ";
    cin >> player_choice ;
    cout << endl << "Player choose " << player_choice << endl;
    cout << "Computer choose " << rand() % 3 << endl;

    return 0;
}
