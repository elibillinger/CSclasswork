//
// Created by Eli Billinger on 10/11/20.
//
using namespace std;
#include <string>
#include <set>

class tic_tac_toe{
public:
    void generate_boards();
    void output();

private:
    int x_winner = 0; // num of x wins
    int o_winner = 0; // num of o wins
    int tie = 0; // num of ties
    set<string> possible_boards; // set of possible_boards
    void test_possible(string current_board); // tests board to see if it is possible
    bool winner_test(string current_board); // tests board to see if a winner has been reached
    void count_winners(); // counts number of wins and ties
};

#ifndef PROJECT2_CLASS_H
#define PROJECT2_CLASS_H

#endif //PROJECT2_CLASS_H
