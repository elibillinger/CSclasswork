/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019


    Updated By: Eli Billinger
    On: 12/10/2020
*/
#ifndef _MAP_MODEL_H
#define _MAP_MODEL_H

#include <iostream>
#include <string>
#include <map>

#include "model.h"

using namespace std;

class map_model : public markov_model {
public:
    virtual void initialize(string text, int order);

    virtual string generate(int size);

    string to_string();

protected:
    string saved_text;
    int saved_order;
    map < string, vector<char> > char_map;
};

#endif
