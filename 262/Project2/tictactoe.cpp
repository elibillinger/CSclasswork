//
// Created by Eli Billinger on 10/11/20.
//

#include "tictactoe.h"
#include <iostream>
using namespace std;

void tic_tac_toe::test_possible(string current_board) {
    int x_count = 0; //count number of X's in board
    int o_count = 0; //count number of O's in board
    for(char c: current_board){
        if(c == 'X'){
            x_count += 1; // if a character in the board string is a X and one to X counter
        } else if(c == 'O'){
            o_count += 1; // if a character in the board string is a O and one to O counter
        }
    }

    if(o_count <= x_count){ // check if number of o's is equal to or less than number of x's
        if(abs(x_count-o_count) <= 1){
            possible_boards.insert(current_board);
        }
    }

}


//generates all possible tic tac toe game boards
void tic_tac_toe::generate_boards() {
    string current_board;
    for(int i = 0; i < 986410; i++){ //generate all possible boards
        int c = i; // use board number to determine X's and O's
        current_board = "         "; // initialize boards as empty
        for (int j = 0; j < 9; j++){
            if (c%3 == 1){
                current_board[j] = 'X';
            } else if(c%3 == 2){
                current_board[j] = 'O';
            }
            c /= 3; // divide the board number by three for each play
            if(winner_test(current_board)){ //check if board is a winner using winner_test function if it does break
                break; // breaks loop from finishing generating current board since it has a winner
            }

        }
        test_possible(current_board); // tests the board to see if it is possible
    }

}




void tic_tac_toe::output() {
    count_winners();
    cout << "total boards: " << possible_boards.size() <<", wins for 'O': ";
    cout << o_winner << ", wins for 'X': " << x_winner << ", ties: " << tie;
    for(string s: possible_boards){ // output each board in the set
        cout << s << endl;
    }
}


//tests board to see if a winner has been reached by testing all possible winning combinations
// if a board has reached a winner it sends it be tested to make sure it is a valid board
// returns true to break the continued generation of the board.
bool tic_tac_toe::winner_test(string current_board) {

    if((current_board[0] =='O'||current_board[0] == 'X') &&  current_board[0] == current_board[1] && current_board[0] == current_board[2]){
        test_possible(current_board);
        return true;
        }
    if((current_board[0] =='O'||current_board[0] == 'X') &&  current_board[0] == current_board[4] && current_board[0] == current_board[8]){
        test_possible(current_board);
        return true;
     }
    if((current_board[3] == 'X'||current_board[3] =='O') &&  current_board[3] == current_board[4] && current_board[3] == current_board[5]){
        test_possible(current_board);
        return true;
    }
    if((current_board[6] =='O'||current_board[6] == 'X') &&  current_board[6] == current_board[7] && current_board[6] == current_board[8]){
        test_possible(current_board);
        return true;
    }
    if((current_board[0] =='O'||current_board[0] == 'X') &&  current_board[0] == current_board[3] && current_board[0] == current_board[6]){
        test_possible(current_board);
        return true;
    }
    if((current_board[6] =='O'||current_board[6] == 'X') &&  current_board[6] == current_board[4] && current_board[6] == current_board[2]){
        test_possible(current_board);
        return true;
    }
    if((current_board[1] =='O'||current_board[1] == 'X') &&  (current_board[1] == current_board[7]) && (current_board[1] == current_board[4])){
        test_possible(current_board);
        return true;
    }
    if((current_board[2] =='O'||current_board[2] == 'X') &&  (current_board[2] == current_board[5]) && (current_board[2] == current_board[8])) {
        test_possible(current_board);
        return true;
    }
}


// counts the number of times the game has been won by x and o
// goes through the set of boards already verified
// also counts the number of ties
void tic_tac_toe::count_winners() {
    for(string s: possible_boards) {
        if ((s[0] == 'O') && s[0] == s[1] && s[0] == s[2]) {
            o_winner++;
        }else if ((s[0] == 'X') && s[0] == s[1] && s[0] == s[2]) {
            x_winner++;
        }else if ((s[0] == 'O') && s[0] == s[4] && s[0] == s[8]) {
            o_winner++;
        }else if ((s[0] == 'X') && s[0] == s[4] && s[0] == s[8]) {
            x_winner++;
        }else if ((s[3] == 'X') && s[3] == s[4] && s[3] == s[5]) {
            x_winner++;
        }else if ((s[3] == 'O') && s[3] == s[4] && s[3] == s[5]) {
            o_winner++;
        }else if ((s[6] == 'O') && s[6] == s[7] && s[6] == s[8]) {
            o_winner++;
        }else if ((s[6] == 'X') && s[6] == s[7] && s[6] == s[8]) {
            x_winner++;
        }else if ((s[0] == 'O') && s[0] == s[3] && s[0] == s[6]) {
            o_winner++;
        }else if ((s[0] == 'X') && s[0] == s[3] && s[0] == s[6]) {
            x_winner++;
        }else if ((s[6] == 'O') && s[6] == s[4] && s[6] == s[2]) {
            o_winner++;
        }else if ((s[6] == 'X') && s[6] == s[4] && s[6] == s[2]) {
            x_winner++;
        }else if ((s[1] == 'O') && (s[1] == s[7]) && (s[1] == s[4])) {
            o_winner++;
        }else if ((s[1] == 'X') && (s[1] == s[7]) && (s[1] == s[4])) {
            x_winner++;
        }else if ((s[2] == 'O') && (s[2] == s[5]) && (s[2] == s[8])) {
            o_winner++;
        }else if ((s[2] == 'X') && (s[2] == s[5]) && (s[2] == s[8])) {
            x_winner++;
        } else { // check for tie if no winner is found
            int counter = 0;
            for (char c:s) { // find char in the string
                if (c == ' ') { // if it is a space increase the counter
                    counter++;
                }
            }
            if (counter == 0) { // if no space were found than it reached a tie
                tie++;
            }
        }
    }
}