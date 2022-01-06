/* CSCI 261 Lab 4C: Loop Errors
*
* Author: Eli Billinger
*
* Correcting the errors in "LoopErrors_main.cpp"
*/

#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to Loop World" << endl;

// SECTION I: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = to make inclusive make i <= numIter and had to set sum to 0 to start with.
// TESTS: 2 => 3, 5 => 15 , 20 => 210

    cout << endl;
    cout << "******************" << endl;
    cout << "Section I" << endl;
    cout << "******************" << endl;

    int sum = 0;      // Accumulates the total
    int i;        // Used as loop control variable
    int numIter;  // The number of times to iterate
    cout << "Enter a number greater than 1 to sum up to: ";
    cin >> numIter;
    for (i = 1; i <= numIter; ++i) {
        sum += i;
    }
    cout << "The sum of the numbers from 1 to " << numIter << " (inclusive) is: " << sum << endl;

// SECTION II: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = had to initialize total to be able to add and remove setting it to zero in loop otherwise it resets every loop
// TESTS: (2, 5, 5)=> 10 , (5 , 5, 5, 5, 5, 5) => 25

    cout << endl;
    cout << "******************" << endl;
    cout << "Section II" << endl;
    cout << "******************" << endl;

    double total = 0;     // Accumulates total
    double price;     // Gets next price from user
    int numItems;     // Number of items
    int counter = 1;  // Loop control counter

    cout << "How many items do you have? ";
    cin >> numItems;
    cout << endl;

    while (counter <= numItems) {
        cout << "Enter the price of item " << counter << ": ";
        cin >> price;
        cout << endl;
        total += price;
        counter++;
    }
    cout << "The total price is: " << total << endl;

// SECTION III: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = had to add one to counter2 each time and make the loop end when the counter reaches numIter2
// TESTS: 2 => 5, 5 => 15 , 20 => 210

    cout << endl;
    cout << "******************" << endl;
    cout << "Section III" << endl;
    cout << "******************" << endl;

    int sum2 = 0;
    int counter2 = 1;
    int numIter2;

    cout << "What number do you wish me to sum to?" << endl;
    cin >> numIter2;

    do {
        sum2 += counter2;
        cout << "Sum so far: " << sum2 << endl;
        counter2 += 1;
    } while (counter2 <= numIter2);

    cout << endl << "Section III Recap" << endl;

    cout << "I calculated the sum of numbers from 1 to " << numIter2 << " (inclusive) as " << sum2 << endl;


// SECTION IV: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = had to set i3 to start at 1 and end the loop of numIter3
// TESTS: 2 => 5, 5 => 55, 10 => 385

    cout << endl;
    cout << "******************" << endl;
    cout << "Section IV" << endl;
    cout << "******************" << endl;

    cout << "I will now calculate ";
    cout << "the sum of squares from 1 to ? (inclusive)" << endl;

    int numIter3;
    cin >> numIter3;

    int sum3 = 0;
    for (int i3 = 1; i3 <= numIter3; i3++) {
        sum3 += i3*i3;
    }

    cout << "The sum of squares from 1 to " << numIter3 << " is: " << sum3 << endl;

// SECTION V: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = move adding counter to inside loop, end the loop once it reaches numIter4
// TESTS: 2 => 9 5 => 225  10 => 3025

    cout << endl;
    cout << "******************" << endl;
    cout << "Section V" << endl;
    cout << "******************" << endl;

    cout << "I will now calculate ";
    cout << "the sum of cubes from 1 to ? (inclusive)" << endl;

    int numIter4;
    cin >> numIter4;

    int sum4 = 0;
    int counter4 = 1;

    while (counter4 <= numIter4) {
        sum4 += (counter4 * counter4 * counter4);
        counter4++;
    }


    cout << "The sum of cubes from 1 to " << numIter4 << " is: " << sum4 << endl;

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Done" << endl;
    cout << "******************" << endl;

    cout << endl << "Congrats!  You fixed them all (hopefully correctly!)" << endl << endl << "Goodbye" << endl << endl;

    return 0;
}
