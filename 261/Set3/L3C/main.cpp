/* CSCI 261 Lab 3C: Pretty Math Solver
 *
 * Author: Eli Billinger
 *
 * Same as 3B except the output is changed
 */
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    double numOne;
    char mathOperator;
    double numTwo;
    double answer;

    // open file
    ifstream mathWorksheet("mathWorksheet.txt");

    // check for error
    if(mathWorksheet.fail()){
        cerr << "Error in opening mathWorksheet.txt";
        return -1;
    }

    // read data and use it
    mathWorksheet >> numOne;
    mathWorksheet >> mathOperator;
    mathWorksheet >> numTwo;

    // find answer to worksheet equation
    switch(mathOperator){
        case '+':
            answer = numOne + numTwo;
            break;
        case '-':
            answer = numOne - numTwo;
            break;
        case '*':
            answer = numOne * numTwo;
            break;
        case '/':
            answer = numOne / numTwo;
            break;
    }

    cout  << setw(11) << right << numOne << endl;
    cout  << left << mathOperator << setw(10) << right << numTwo << endl;
    cout <<  setfill('=')<< setw(11) << right << '='<< endl;
    cout << setfill(' ') <<setw(11) << right << answer << endl;

    // close the file
    mathWorksheet.close();

    return 0;
}
