// function.cpp A6
// Created by Eli Billinger
//
// USING 3 SKIP DAYS 2 REMAINING
//creatd function for each of the tasks
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
#include "functions.h"
string promptUserForFilename(){
    string fileName;
    cout << "Enter filename:";
    getline(cin, fileName);
    return fileName;
}
bool openFile(ifstream &fileIn,string filename){
    fileIn.open(filename);
    if(fileIn.is_open()){
        return true;
    } else {
        return false;
    }
}

vector<string> readWordsFromFile(ifstream &fileIn){
    vector<string> words;
    string word;
    while(fileIn >> word){
        words.push_back(word);
    }
    return words;
}
void removePunctuation(vector<string> &allWords, string punctuation){
    for (int i = 0; i < allWords.size(); i++){
        for (int j = 0; j < punctuation.length(); j++){
            for ( int k = 0; k < allWords.at(i).length(); k++){
                if( allWords.at(i)[k] == punctuation[j]){
                    allWords.at(i).erase(k--,1);
                }

            }
        }
    }
}

void capitalizeWords(vector<string> &allWords){
    for(int i = 0; i < allWords.size(); i++){
        for (int j = 0; j < allWords.at(i).length(); j++){
            if(allWords.at(i).at(j)>='a' && allWords.at(i).at(j)<='z'){
                allWords.at(i).at(j) = allWords.at(i).at(j) - 32;
            }
        }
    }
}

vector<string> filterUniqueWords(vector<string> allWords){
    vector<string> uniqueWords;
    for(int i = 0; i < allWords.size(); i++){
        string word = allWords.at(i);
        bool unique = inUniqueWords(uniqueWords,word);
        if (unique){
            uniqueWords.push_back(word);
        }
    }
    return uniqueWords;
}

//  compare word to unique words     (added to seperate for better veiwing and to figure out)
bool inUniqueWords(vector<string> uniqueWords, string word) {
    for( int i = 0; i < uniqueWords.size(); i++){
        if(word.compare(uniqueWords.at(i)) == 0){
            return false;
        }
    }
    return true;
}

void alphabetizeWords(vector<string> &uniqueWords) {
    for (int j = 0; j < uniqueWords.size(); j++) {
        for (int i = 0; i < uniqueWords.size(); i++) {
            while (i + 1 < uniqueWords.size()) {
                if (uniqueWords.at(i) > uniqueWords.at(i + 1)) {
                    string temp;
                    temp = uniqueWords.at(i);
                    uniqueWords.at(i) = uniqueWords.at(i + 1);
                    uniqueWords.at(i + 1) = temp;
                    break;
                } else break;
            }
        }
    }
}

vector <unsigned int> countUniqueWords(vector<string> allWords, vector<string> uniqueWords){
    vector <unsigned int> numUniqueWords;
    for( int i = 0; i < uniqueWords.size(); i++){
        int counter = 0;
        for(int j = 0; j < allWords.size(); j++){
            if(uniqueWords.at(i) == allWords.at(j)){
                counter++;
            }
        }
        numUniqueWords.push_back(counter);
    }
    return numUniqueWords;
}

void printWordsAndCounts(vector<string> uniqueWords,vector<unsigned int> uniqueWordCounts ){
    // determine length of longest word
    cout << "\nWord Counts" << endl;
    int largestSizeWord = 0; int count = 0;
    for( int i =0; i < uniqueWords.size(); i++){
        if(uniqueWords.at(i).size() > largestSizeWord){
            largestSizeWord = uniqueWords.at(i).size();
        }
    }
    // determine digits of number of unique words
    int n = uniqueWords.size();
    while ( n != 0) {
        n = n / 10;
        ++count;
    }


    for ( int i = 0; i < uniqueWords.size(); i++){
        cout << setw(count)  << right << i+1 << " : ";
        cout << setw(largestSizeWord) << left << uniqueWords.at(i) << " : ";
        cout << setw(2) << uniqueWordCounts.at(i)  << endl;
    }
}

void countLetters (unsigned int letters[26], vector<string> allWords){
    for (int i = 0; i < allWords.size(); i++) {
        string word = allWords[i];
        for (int j = 0; j < word.size(); j++) {
            letters[word[j] - 'A']++;
        }
    }
}

void printLetterCounts(unsigned int letters[26]){
    string allLetters = "ABCDEFGHIJCKLMOPQRSTUVWXYZ";
    cout << "\nLetter Counts" << endl;
    int largestNum = 0; int count = 0;
    for( int i =0; i < 26; i++){
        if(letters[i] > largestNum){
            largestNum = letters[i];
        }
    }
    // determine digits of number of unique words
    int n = largestNum;
    while ( n != 0) {
        n = n / 10;
        ++count;
    }
    for ( int i = 0; i < 26; i++){
        cout << allLetters[i] << " : ";
        cout << setw(count) << right << letters[i] << endl;
    }
}

void printMaxMinWord(vector<string> uniqueWords, vector<unsigned int> uniqueWordCounts){
    string longerWord;
    string smallerWord;
    int smallWordCount = 100, smallLocation = 0, largeLocation = 0, largeWordCount = 0 , count = 0, count1 = 0;
    for (int i = 0; i < uniqueWordCounts.size(); i++){
        if(uniqueWordCounts.at(i) < smallWordCount){
            smallWordCount = uniqueWordCounts.at(i);
            smallLocation = i;
        }
        if(uniqueWordCounts.at(i) > largeWordCount){
            largeWordCount = uniqueWordCounts.at(i);
            largeLocation = i;
        }
    }
    // determine percentage
    double totalNumWords = 0;
    for (int i = 0; i < uniqueWordCounts.size(); i++){
        totalNumWords += uniqueWordCounts.at(i);
    }
    double smallPercent , largePercent;
    smallPercent =(smallWordCount/totalNumWords) * 100;
    largePercent = (largeWordCount/totalNumWords) * 100;
    // determine width for words
    int largestSizeWord = uniqueWords.at(smallLocation).size();
        if(uniqueWords.at(largeLocation).size() > largestSizeWord){
            largestSizeWord = uniqueWords.at(largeLocation).size();
        }
    // determine width for count and percent
    int n = largeWordCount;
    while ( n != 0) {
        n = n / 10;
        ++count;
    }
    int l = int(largePercent);
    while ( l != 0) {
        l = l / 10;
        ++count1;
    }
    //outputs
    cout << "\nLeast Frequent Word: " << setw(largestSizeWord) << left << uniqueWords.at(smallLocation) << " ";
    cout << setw(count) << right<< smallWordCount << " ";
    cout << "( " << setw(count1+4)<< right << fixed <<  setprecision(3)<< smallPercent << "%)"<< endl;

    cout << "Most Frequent Word:  " << setw(largestSizeWord) << left << uniqueWords.at(largeLocation) << " ";
    cout << setw(count) << right<< largeWordCount << " ";
    cout << "( " << setw(count1+4)<< right << fixed <<  setprecision(3)<< largePercent << "%)"<< endl;
}

void printMaxMinLetter(unsigned int letters[26]){
    int smallLetterCount = 100, smallLocation = 0, largeLocation = 0, largeLetterCount = 0 , count = 0, count1 = 0;
    for (int i = 0; i < 26; i++){
        if(letters[i] < smallLetterCount){
            smallLetterCount = letters[i];
            smallLocation = i;
        }
        if(letters[i] > largeLetterCount){
            largeLetterCount = letters[i];
            largeLocation = i;
        }
    }
    // determine percentage
    double totalNumLetters = 0;
    for (int i = 0; i < 26; i++){
        totalNumLetters += letters[i];
    }
    double smallPercent , largePercent;
    smallPercent =(smallLetterCount/totalNumLetters) * 100;
    largePercent = (largeLetterCount/totalNumLetters) * 100;

    // determine corresponding letter
    string allLetters = "ABCDEFGHIJCKLMOPQRSTUVWXYZ";
    char smallLetter, largeLetter;
    smallLetter = allLetters[smallLocation];
    largeLetter = allLetters[largeLocation];

    // determine width for count and Percent
    int n = largeLetterCount;
    while ( n != 0) {
        n = n / 10;
        ++count;
    }
    int l = int(largePercent);
    while ( l != 0) {
        l = l / 10;
        ++count1;
    }
    //output
    cout << "\nLeast Frequent Letter: " << setw(1) << left << smallLetter << " ";
    cout << setw(count) << right<< smallLetterCount << " ";
    cout << "( " << setw(count1+4)<< right << fixed <<  setprecision(3)<< smallPercent << "%)"<< endl;

    cout << "Most Frequent Letter:  " << setw(1) << left << largeLetter << " ";
    cout << setw(count) << right<< largeLetterCount << " ";
    cout << "( " << setw(count1+4)<< right << fixed <<  setprecision(3)<< largePercent << "%)"<< endl;
}
