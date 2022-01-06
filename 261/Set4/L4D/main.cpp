/* CSCI 261 Lab 4D: Input Paradigms to Compute Averages
*
* Author: Eli Billinger
*
* Using loops to read to different types of files
* one is in counter format and one is in sentinel format
*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    float lineValue;
    int userChoice;
    float average = 0;
    cout << "Which file would you like to open\n1. Counter Controlled\n2. Sentinel Controlled" << endl;
    cin >> userChoice;
    if(userChoice == 1) {
        ifstream counterControlled("counter_controlled.txt");
        if (counterControlled.fail()) {
            cerr << "Error in opening counter_controlled.txt";
            return -1;
        }
        int numLines;
        counterControlled >> numLines;
        cout << "There are " << numLines << " values in the file." << endl;
        cout << "The values in the file are:" << endl;
        for ( int i = 1; i <= numLines; i++ ){
            counterControlled >> lineValue;
            cout << setprecision(1)<< fixed << lineValue << endl;
            average += lineValue;
        }
        average = average / numLines;
        cout << setprecision(2) << fixed << "The average is " << average  << "." << endl;

    } else {
        ifstream sentinelControlled("sentinel_controlled.txt");
        if (sentinelControlled.fail()) {
            cerr << "Error in opening counter_controlled.txt";
            return -1;
        }
        const int SENTINAL_VALUE = -9999;
        int counter;
        cout << "The values in the file are:" << endl;
        while(true){
            sentinelControlled >> lineValue;
            if ( lineValue == SENTINAL_VALUE){
                break;
            }
            cout << setprecision(1) << fixed << lineValue << endl;
            counter += 1;
            average += lineValue;
        }
        average = average/counter;
        cout << "There are " << counter << " values in the file." << endl;
        cout << setprecision(2) << fixed << "The average is " << average  << "." << endl;
    }

    return 0;
}
