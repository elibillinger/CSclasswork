/*
    hangman.cpp
        
    Method implementations for the hangman class.
    
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


#include "hangman.h"

using namespace std;

// constructor
hangman::hangman() {
    string word;
    ifstream dictionary("dictionary.txt");
    if (dictionary.fail()) {
        cerr << "Could not open 'dictionary.txt' " << endl;
    }
    while(!dictionary.eof()){
        getline(dictionary,word);
        words.insert(word);
    }
    dictionary.close();
}

int hangman::get_word_length(string msg) {
    set<int> word_lengths;
    for(string n: words){
        word_lengths.insert(n.length());
    }

    while(true){
        string input;
        int result = 0;
        cout << msg << endl;
        getline(cin,input);
        result = atoi(input.c_str());
        if(word_lengths.find(result) != word_lengths.end()){
            return result;
        }
        cout << "There are no words of that length. Enter another length.";
        cout << endl;
    }
}

// start_new_game()
//
// Setup a new game of hangman.
void hangman::start_new_game(int num_guesses, int length,bool running_words) {
    // TODO: Initialize game state variables
    display_family = running_words;
    guess_num = num_guesses;
    word_length = length;
    words_of_length.clear();
    word_state = "";
    guesses = "";
    //create blank word for output
    for(int i=0; i < word_length; i++){
        word_state += '-';
    }
    // add all words of the correct length to a set
    for(string n: words){
        if( n.length() == word_length){
            words_of_length.insert(n);
        }
    }
    family = words_of_length;
}


// process_guess()
//
// Process a player's guess - should return true/false depending on whether
// or not the guess was in the hidden word.  If the guess is incorrect, the
// remaining guess count is decreased.
bool hangman::process_guess(char c) {
    guesses = guesses + c; //add guess to string of previous guesses
    word_families.clear(); // clear word_familes map for reuse

    // create all of the word families
    for(string n: family){
        string blank = word_state;
        for(int i = 0; i < word_length; i++){
            if(n[i] == c){
                blank[i] = c;
            }
        }
        word_families[blank].insert(n);
    }

    //find largest family and chose it as family
    int longest_family = 0;
    for( auto entry: word_families){
        set<string> temp = entry.second;
        if(longest_family<temp.size()){
            longest_family = temp.size();
            family = temp;
            word_state = entry.first;
        }
    }

    //if the largest family contains the guess return true
    for(char letter: word_state){
        if(letter == c){
            return true;
        }
    }

    // if not decrease number of guess and return false
    guess_num -= 1;
    return false;
}

// get_display_word()
//
// Return a representation of the hidden word, with unguessed letters
// masked by '-' characters.
string hangman::get_display_word() {
    return word_state;
}


// get_guesses_remaining()
//
// Return the number of guesses remaining for the player.
int hangman::get_guesses_remaining() {
    return guess_num;
}


// get_guessed_chars()
//
// What letters has the player already guessed?  Return in alphabetic order.
string hangman::get_guessed_chars() {
    return guesses;
}


// was_char_guessed()
//
// Return true if letter was already guessed.
bool hangman::was_char_guessed(char c) {
    for( char letter: guesses){
        if(letter == c){
            return true;
        }
    }
    return false;
}


// is_won()
//
// Return true if the game has been won by the player.
bool hangman::is_won() {
    if(word_state != ""){
        int counter = 0;
        for(char c: word_state){
            if(c == '-'){
                counter++;
            }
        }
        if(counter == 0){
            return true;
        }
        return false;
    }
    return false;
}


// is_lost()
//
// Return true if the game has been lost.
bool hangman::is_lost() {
    if(guess_num == 0){
        int counter = 0;
        for(char c: word_state){
            if(c == '-'){
                counter++;
            }
        }
        if(counter > 0){
            return true;
        }
    }
    return false;
}


// get_hidden_word
//
// Return the true hidden word to show the player.
string hangman::get_hidden_word() {
    //randomly choose word in family as word
    string word;
    int length = family.size()-1;
    srand(time(0));
    int random = rand() % (length);
    auto first = family.begin();
    advance(first,random); // from algorithm library removes words from 0 to random from family set.
    word = *first;
    return word;
}


void hangman::family_words() {
    if(display_family){
        cout << "Words in chosen family: " << family.size() << endl;
    }
}