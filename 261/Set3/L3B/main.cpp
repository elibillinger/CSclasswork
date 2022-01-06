/* CSCI 261 Lab 3B: Math Worksheet Solver
 *
 * Author: Eli Billinger
 *
 * Read the file from 3A and solve the math problem
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

    cout << numOne << " " << mathOperator << ' ' << numTwo << " = " << answer << endl;

    // close the file
    mathWorksheet.close();

    return 0;
}
