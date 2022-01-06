/* CSCI 261 Lab 3A: Math Worksheet Generator
 *
 * Author: Eli Billinger
 *
 * Practice writing a file
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
// generate numbers and operator
    srand(time(0));
    rand();
    float numOne = 200*(float)rand()/(RAND_MAX+1)+100;
    float numTwo = 200*(float)rand()/(RAND_MAX+1)+100;
    int mathOp = rand() % 4 + 1;
    char mathOperator;
    switch (mathOp){
        case 1:
            mathOperator = '+';
            break;
        case 2:
            mathOperator = '-';
            break;
        case 3:
            mathOperator = '*';
            break;
        case 4:
            mathOperator = '/';
            break;
    }


    //open file
    ofstream mathWorksheet ("mathWorksheet.txt");

    // check for errors
    if(mathWorksheet.fail()){
        cerr << "Error Opening mathWorksheet.txt";
        return -1;
    }

    //write the data
    mathWorksheet << setprecision(2)<< fixed << numOne << " " << mathOperator << " " << numTwo << " = ?"<< endl;

    // close the file
    mathWorksheet.close();
    return 0;
}
