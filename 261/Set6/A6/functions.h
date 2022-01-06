//function.h A6
// Created by Eli Billinger
//
//USING 3 SKIP DAYS 2 REMAINING

#ifndef A6_FUNCTIONS_H
#define A6_FUNCTIONS_H

string promptUserForFilename();
bool openFile(ifstream &fileIn,string fileName);
vector<string> readWordsFromFile(ifstream &fileIn);
void removePunctuation(vector<string> &allWords, string punctuation);
void capitalizeWords(vector<string> &allWords);
vector<string> filterUniqueWords(vector<string> allWords);
bool inUniqueWords(vector<string> uniqueWords, string word);//search for word in unique word vector
void alphabetizeWords(vector<string> &uniqueWords);
vector <unsigned int> countUniqueWords(vector<string> allWords, vector<string> uniqueWords);
void printWordsAndCounts(vector<string> uniqueWords,vector<unsigned int> uniqueWordCounts );
void countLetters (unsigned int letters[26], vector<string> allWords);
void printLetterCounts(unsigned int letters[26]);
void printMaxMinWord(vector<string> uniqueWords, vector <unsigned int> uniqueWordCounts);
void printMaxMinLetter(unsigned int letters[26]);
#endif //A6_FUNCTIONS_H
