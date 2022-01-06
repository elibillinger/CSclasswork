/* CSCI261 Lab5C: stringTest
 *
 * Author: Eli Billinger
 *
 * This program executes some tests that illustrate the properties
 * and behaviors of strings.
 *
 * Copyright 2019 Dr. Jeffrey Paone

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
 *
*/

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void runAllTests();

int main() {

    cout << "Testing your functions...\n\n";
    runAllTests();

    // Exit program.
    return 0;
}


// A generic test function, that simply prints "PASSED" if b is true
// and otherwise prints false. Do not modify this function.
void test(const string MESSAGE, const string LHS, const string RHS)  {
    cout << setw(30) << right;
    cout << MESSAGE << ": ";
    cout << left;
    if (LHS == RHS)
        cout << "    PASSED   \n";
    else
        cout << " !!>FAILED<!! \"" << LHS << "\" != \"" << RHS << "\"\n";
}

// A generic test function, that simply prints "PASSED" if b is true
// and otherwise prints false. Do not modify this function.
void test(const string MESSAGE, const char LHS, const char RHS)  {
    cout << setw(30) << right;
    cout << MESSAGE << ": ";
    cout << left;
    if (LHS == RHS)
        cout << "    PASSED   \n";
    else
        cout << " !!>FAILED<!! '" << LHS << "' != '" << RHS << "'\n";
}

// A generic test function, that simply prints "PASSED" if b is true
// and otherwise prints false. Do not modify this function.
void test(const string MESSAGE, const int LHS, const int RHS)  {
    cout << setw(30) << right;
    cout << MESSAGE << ": ";
    cout << left;
    if (LHS == RHS)
        cout << "    PASSED   \n";
    else
        cout << " !!>FAILED<!! " << LHS << " != " << RHS << "\n";
}

// Returns the length of a string
int stringLength(const string STR)  {
    int result = -1;
    result = STR.length();  // set result to the length of the string
    return result;
}

// Returns the character of a string at a given index
char charAt(const string STR, const int IDX) {
    char result = '\0';
    result = STR[IDX];
    return result;
}

// Returns a concatenation of strings left and right
string stringAppend(const string LEFT, const string RIGHT)  {
    string result = LEFT;
    result.append(RIGHT);
    return result;
}

// Returns the result of inserting a string into another at a given position
string stringInsert(const string STR, const string TO_INSERT, const int IDX) {
    string result = STR;
    result.insert(IDX,TO_INSERT);
    return result;
}

// Returns the first index of character c in string s
int stringFind(const string STR, const char C)  {
    int result = -1;
    result = STR.find(C);
    return result;
}

// Returns part of a string
string stringSubstring(const string STR, const int IDX, const int LEN) {
    string result = STR;
    result = result.substr(IDX,LEN);
    return result;
}

// Replaces part of a string
string stringReplace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH) {
    string result = STR;
    result.replace(STR.find(TEXT_TO_REPLACE),TEXT_TO_REPLACE.length(),REPLACE_WITH);
    return result;
}

// Returns the first word, given a sentence
string firstWord(const string STR)  {
    string result = STR;
    result = result.substr(0,result.find_first_of(" "));
    return result;
}

// Returns the string with the first word removed
string removeFirstWord(const string STR)  {
    string result = STR;
    if(result.find(" ") == string::npos){
        result.replace(0,result.find_first_of(" "),"");
    } else {
        result = STR.substr(STR.find_first_of(" ")+1,STR.length());
    }
    return result;
}

// Returns the second word, given a sentence
string secondWord(const string STR)  {
    string result = STR;
    result = STR.substr(STR.find_first_of(" ")+1,STR.length());
    result = result.substr(0,result.find_first_of(" "));
    return result;
}

// Returns the third word, given a sentence
string thirdWord(const string STR)  {
    string result = STR;
    result = STR.substr(STR.find_first_of(" ")+1,STR.length());
    result = result.substr(result.find_first_of(" ")+1,result.length());
    result = result.substr(0,result.find_first_of(" "));
    return result;
}

// Returns the nth word, given a sentence
string nthWord(const string STR, const int N)  {
    string result = STR;
        for(int i=1; i<N; i++){
        result = result.substr(result.find_first_of(" ")+1,result.length());
    }
    result = result.substr(0,result.find_first_of(" "));
    return result;
}

// Returns a string substituting character target with string replacement
string substitute(const string STR, const string TARGET, const string REPLACEMENT)  {
    string result = STR;
    // TODO 12: set result to be the string with all instances of TARGET replaced
    // variables available: const string STR, const string TARGET, const string REPLACEMENT
    while(true){
        if(result.find(TARGET) != string::npos){
            result.replace(result.find(TARGET),1,REPLACEMENT);
        } else {
            break;
        }
    }
    return result;
}

// Test suite. You should read, but not modify, this function.
void runAllTests()  {
    test( "Testing length()", 			stringLength("Now") , 3 );
    test( "Testing length()", 			stringLength("Tablet") , 6 );
    test( "Testing at()", 				charAt("Elephant", 3) , 'p' );
    test( "Testing at()", 				charAt("Giraffe", 2) , 'r' );
    test( "Testing append()", 			stringAppend("There's a ", "natural mystic.") , "There's a natural mystic." );
    test( "Testing append()", 			stringAppend("It's the ", "eye of the tiger.") , "It's the eye of the tiger." );
    test( "Testing insert()", 			stringInsert("If you carefully.", "listen ", 7) , "If you listen carefully." );
    test( "Testing insert()", 			stringInsert("carefully.", "Watch ", 0) , "Watch carefully." );
    test( "Testing find()", 			stringFind("Have to face reality now.", 'o') , 6 );
    test( "Testing find()", 			stringFind("Have to face reality now.", 'e') , 3 );
    test( "Testing substr()", 			stringSubstring("Such a natural mystic", 7, 7) , "natural" );
    test( "Testing substr()", 			stringSubstring("Such a natural mystic", 0, 4) , "Such" );
    test( "Testing replace()", 			stringReplace("Strings are not the way", "Strings", "Things") , "Things are not the way" );
    test( "Testing replace()", 			stringReplace("Show me the things", "things", "way") , "Show me the way" );
    test( "Testing firstWord()", 		firstWord("The quick brown fox jumped over the lazy dog") , "The" );
    test( "Testing firstWord()", 		firstWord("A man a plan a canal Panama") , "A" );
    test( "Testing firstWord()", 		firstWord("I have the hang of this") , "I" );
    test( "Testing removeFirstWord()",  removeFirstWord("The quick brown fox jumped over the lazy dog") , "quick brown fox jumped over the lazy dog" );
    test( "Testing removeFirstWord()",  removeFirstWord("Goodbye") , "" );
    test( "Testing removeFirstWord()",  removeFirstWord(removeFirstWord("The quick brown fox jumped over the lazy dog")) , "brown fox jumped over the lazy dog" );
    test( "Testing secondWord()", 		secondWord("The quick brown fox jumped over the lazy dog") , "quick" );
    test( "Testing secondWord()", 		secondWord("A man a plan a canal Panama") , "man" );
    test( "Testing secondWord()", 		secondWord("I have the hang of this") , "have" );
    test( "Testing thirdWord()", 		thirdWord("The quick brown fox jumped over the lazy dog") , "brown" );
    test( "Testing thirdWord()", 		thirdWord("A man a plan a canal Panama") , "a" );
    test( "Testing thirdWord()", 		thirdWord("I have the hang of this") , "the" );
    test( "Testing nthWord(1)", 		nthWord("The quick brown fox jumped over the lazy dog", 1) , "The" );
    test( "Testing nthWord(2)", 		nthWord("The quick brown fox jumped over the lazy dog", 2) , "quick" );
    test( "Testing nthWord(3)", 		nthWord("The quick brown fox jumped over the lazy dog", 3) , "brown" );
    test( "Testing nthWord(4)", 		nthWord("The quick brown fox jumped over the lazy dog", 4) , "fox" );
    test( "Testing nthWord(5)", 		nthWord("The quick brown fox jumped over the lazy dog", 5) , "jumped" );
    test( "Testing nthWord(6)", 		nthWord("The quick brown fox jumped over the lazy dog", 6) , "over" );
    test( "Testing nthWord(7)", 		nthWord("The quick brown fox jumped over the lazy dog", 7) , "the" );
    test( "Testing nthWord(8)", 		nthWord("The quick brown fox jumped over the lazy dog", 8) , "lazy" );
    test( "Testing nthWord(9)", 		nthWord("The quick brown fox jumped over the lazy dog", 9) , "dog" );
    test( "Testing substitute()", 		substitute("The Gxxgle", "x", "o") , "The Google" );
    test( "Testing substitute()", 		substitute("$chool of Mine$", "$", "s") , "school of Mines" );
    test( "Testing substitute()", 		substitute(substitute("D--", "-", "+"), "D", "C") , "C++" );
}
