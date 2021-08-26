#ifndef _HANGMAN_H
#define _HANGMAN_H

/*
    hangman.h
        
    Class definition for the hangman class.

    assignment: CSCI 262 Project - Evil Hangman        

    author: Eli Billinger

    last modified: 10/25/2020
*/

#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <algorithm>


using namespace std;

/******************************************************************************
   class hangman

   Maintains game state for a game of hangman.

******************************************************************************/

class hangman {
public:
    hangman();

    int get_word_length(string msg);

    // start a new game where player gets num_guesses unsuccessful tries
	void start_new_game(int num_guesses,int word_length, bool running_words);

    // player guesses letter c; return whether or not char is in word
    bool process_guess(char c);

    // display current state of word - guessed characters or '-'
    string get_display_word();

    // How many guesses remain?
	int get_guesses_remaining();

    // What characters have already been guessed (for display)?
    string get_guessed_chars();

    // Has this character already been guessed?
    bool was_char_guessed(char c);

    // Has the game been won/lost?  (Else, it continues.)
    bool is_won();
    bool is_lost();

    // Return the true hidden word.
    string get_hidden_word();

    //print the number of words in the family
    void family_words();

private:
    bool display_family;
    set<string> words;
    set<string> words_of_length;
    set<string> family;
    string guesses;
    string word_state;
    int guess_num;
    int word_length;
    map<string,set<string>> word_families;
    
};

#endif
