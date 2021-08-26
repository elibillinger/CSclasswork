/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019



    Updated By: Eli Billinger
    On: 12/10/2020
*/

#include "map_model.h"

void map_model::initialize(string text, int order) {
    saved_text = text + text.substr(0, order);
    saved_order = order;
    for (int i = 0; i < saved_text.size() - saved_order; i++){
        char_map[saved_text.substr(i,saved_order)].push_back(saved_text[i + saved_order]);
    }
}

string map_model::generate(int size) {
    string seed = saved_text.substr(rand() % (saved_text.length() - saved_order), saved_order);
    string answer = seed;
    for (int i = 0; i < size; i++) {
        vector<char> temp = char_map[seed];
        answer += temp[rand() % temp.size()];
        seed = seed.substr(1) + answer.back();
    }
    return answer;
}
