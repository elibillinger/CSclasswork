/*
    parta.cpp

    Author: C. Painter-Wakefield and Luke Henke

    Last modified: 2/6/2020

    Starter code for sets & maps lab, provides initial code
    to load in a dictionary of words, and run time tests on
    how long it takes to search for them.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <chrono>

using namespace std;
using namespace std::chrono;

/*************/
/* CONSTANTS */
/*************/
static const int TEST_SIZE = 4000;    // how many trials will we time?


/********/
/* MAIN */
/********/
int main() {
    // open dictionary and read in all the words
    cout << "Reading dictionary...";
    ifstream fin("dictionary.txt");
    if (!fin) {
        cerr << "Could not open 'dictionary.txt' for reading, exiting." << endl;
        return -1;
    }

    vector<string> words_vec;    // all the words, in a vector
    set<string> words_set;       // all the words, in a set
    string word;
    while (!fin.eof()) {
        getline(fin, word);
        words_vec.push_back(word);
        words_set.insert(word);
    }
    fin.close();
    cout << "done." << endl;


    // create a "small" vector of strings to search for -
    // we'll pick words spaced evenly throughout the collection.
    cout << "Creating test words collection...";
    vector<string> test_words;
    for (int i = 0; i < TEST_SIZE; i++) {
        int index = int(words_vec.size() / double(TEST_SIZE) * i);
        test_words.push_back(words_vec[index]);
    }
    cout << "done." << endl;


    int count;            // how many words did we find?

    cout << "Timing Vector..." << flush;
    auto start = system_clock::now();
    /************** CODE TO BE TIMED ***************/
    count = 0;
    for (string s: test_words) {
        // TODO: **Remove this for loop** and use word_set's .count() method instead!

            if (words_set.count(s)) {
                count++;
            }
    }
    /***********************************************/

    auto stop = system_clock::now();
    cout << "done." << endl << endl;

    // This next line takes the elapsed "clock time" and converts to seconds
    auto diff = duration_cast<nanoseconds>(stop - start);
    double seconds = diff.count() / 1.0e9;

    cout << "Found " << count << " of " << TEST_SIZE << " words in ";
    cout << seconds << " seconds." << endl;

    return 0;
}
