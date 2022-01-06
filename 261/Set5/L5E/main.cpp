/* CSCI 261 Lab 5E: Vector Input/Output
 *
 * Author: Eli Billinger
 *
 * add values to a vector and search the a vector using a for loop
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "Enter as many non-negative numbers as you'd like and I will tell you what they are.\nWhen you  wish to be done, enter -1 to stop entering numbers." << endl;
    vector <int> userNumbers;
    int number,smallest=0,largest=0;
    // get numbers from user and input into vector
    while(true){
        cout << "Your Number Is: ";
        cin >> number;
        if (number == -1){
            break;
        } else{

            userNumbers.emplace_back(number);
        }
    }
    //print out all numbers in vector
    cout << "You entered " << userNumbers.size() << " numbers." << endl;
    cout << "The numbers are: ";
    for(int i =0; i < userNumbers.size();i++){
        cout << userNumbers[i] << " ";
    }
    // determine smallest value and largest value
    smallest = userNumbers[0];
    for(int i =0; i < userNumbers.size();i++){
        if(userNumbers[i] < smallest){
            smallest = userNumbers[i];
        }
        if(userNumbers[i]>largest){
            largest = userNumbers[i];
        }
    }
    cout << "\nThe smallest number is: " << smallest << endl;
    cout << "The largest number is: " << largest << endl;
    cout << "The first number is: " << userNumbers.front() << endl;
    cout << "The last number is: " << userNumbers.back() << endl;
    return 0;
}
