
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;



void babylonian(double number, double guess){
    double last = 1e10;
    while(1e-8 < (last - guess)){
        last = guess;
        double temp = number/guess;
        guess = (guess + temp)/2;
        cout << fixed <<setprecision(8) << guess << endl;
    }
}

void sieve(int number){
    vector<bool> prime(number,true);
    for ( int i = 2; i+i<number; i++){
        if(prime[i]){
            for(int j = i+i; j < number; j+=i){ //iterate every i through vector and set them to false
                prime[j] = false;
            }
        }
    }
    // print out the remaining prime numbers
    for( int i = 2; i < number; i++){
        if(prime[i]){
            cout << i << " ";
        }
    }

}


int main() {
    int choice;
    cout << "Enter a 1 for The Babylonian Method and a 2 for The Sieve of Eratosthenes: ";
    cin >> choice;
    while(choice != 1 && choice != 2){
        cout << "Please enter a valid response of 1 or 2";
        cin >> choice;
    }
    if(choice == 1) {
        double num, guess;
        cout << "Enter a number: ";
        cin >> num;
        cout << "What is your guess? ";
        cin >> guess;
        babylonian(num, guess);
    } else if(choice == 2){
        int max;
        cout << "Enter a maximum number: ";
        cin >> max;
        sieve(max);
    }
    return 0;
}
