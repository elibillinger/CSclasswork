/* CSCI 261 Lab 4B: Multiplication Tables
*
* Author: Eli Billinger
*
*created a multipication table using nested loops
* only took values in between 1 and 11
* assumed user knew to enter values
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int multiplier, multiplicand;
    while(true){
        cin >> multiplier;
        if(multiplier<=1||multiplier>=11){
            continue;
        } else {
            break;
        }
    }
    while(true){
        cin >> multiplicand;
        if(multiplicand<=1||multiplicand>=11){
            continue;
        } else {
            break;
        }
    }
    for(int i = 1; i <= multiplier; i++){
        if ( i == 1){
            cout << setfill('.') << setw(2) << '.';
            for(int k = 1; k <= multiplicand; k++){
                cout << setw(4) << k;
            }
            cout << endl;
        }
        cout << setw(2) << i;

        for(int j = 1; j <= multiplicand; j++){
            cout << setw(4) << i*j;
        }
        cout << endl;
    }
    return 0;
}
