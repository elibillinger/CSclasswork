/* CSCI 261 Lab 1C: GEOMETRIC CALCULATIONS
 *
 * Author: Eli Billinger
 *
 * Create program to find volume of a box and area of a circle
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cmath>
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Must have a function named "main", which is the starting point of a C++ program.
int main() {

    /******** MODIFY OR INSERT CODE BELOW HERE ********/
    int length;
    int width;
    int height;
    int volume;
    // get box dimensions
    cout << "Enter the dimensions of your box: ";
    cin  >> length >> width >> height;
    // Volume of a box is length times width times height.
    volume = length * width * height;
    // output volume
    cout << "The volume of your box is: " << volume << endl;

    double area;
    double radius;
    const double PI = 3.14159;
    const double SQUARE = 2;
    //get circle radius
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    //area of circle is pi times radius squared
    area = PI * (pow(radius,SQUARE));
    cout << "The area of a circle with radius " << radius << " is " << area << endl;
    /******** MODIFY OR INSERT CODE ABOVE HERE ********/
    return 0; // signals the operating system that our program ended OK.
}