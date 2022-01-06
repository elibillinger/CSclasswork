/* CSCI 261 Lab 5A: Array Input/Output
 *
 * Author: Eli Billinger
 *
 * Input values into an array then outputing the values
 */
#include <iostream>
using namespace std;

int main() {
    // initalize array of length 15
    int userNumbers[15];
    cout << "Enter 15 numbers and I will tell you what they are." << endl;

    // loop to ask for number and input it into array
    for(int i=0;i<15;i++){
        int number;
        cout << "Number " << i+1 <<": ";
        cin >> number;
        userNumbers[i] = number;
    }
    cout << "Your Numbers are: ";
    for(int i = 0; i <15; i++){
        cout << userNumbers[i] << " ";
    }

    return 0;
}
