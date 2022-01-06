/* CSCI 261 Lab 2A: Math Equations
 *
 * Authors: Eli Billinger and Sean Emerson
 *
 * Practice pair programming by creating equations
 */
#include <iostream>
using namespace std;

int main() {
    //Equation 1 (stress = F/a)
    double force;
    double acceleration;
    double stress;

    cout << "Enter a force" << endl;
    cin >> force;

    cout << "Enter an acceleration" << endl;
    cin >> acceleration;

     stress = force/acceleration;

     cout << "Your stress is: " << stress << endl;

     //Equation 2 (current= v/r)

     double current;
     double voltage;
     double resistence;

     cout << "Enter a voltage" << endl;
     cin >> voltage;

     cout << "Enter a resistence" << endl;
     cin >> resistence;

     current = voltage/resistence;


     cout << "Your current is:" << current << endl;

    return 0;
}
