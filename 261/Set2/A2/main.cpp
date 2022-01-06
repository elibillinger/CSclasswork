/* CSCI 261 Assignment A2: Triangles
 *
 * Author: Eli Billinger
 *
 * Ask user for 2 side lengths and randomly generate 1
 * determine type of triangle and perimeter and area
 */
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main() {
    const double TOLERANCE = 0.0001;
    double sideOne;
    double sideTwo;
    double sideThree;
    double max;
    double min;
    double range;
    cout << "Enter two real vales: ";
    cin >> sideOne >> sideTwo;

    // generate random number for third side
    srand(time(0));
    rand();
    max = sideOne + sideTwo;
    min = abs(sideOne-sideTwo);
    range = max - min;
    sideThree = (range *(double)rand() / (float)RAND_MAX )+ min;
    cout << sideThree << endl;

    double c;
    double a;
    double b;
    // determine largest side
    if(sideOne >= sideTwo && sideOne >= sideThree){
        c = sideOne;
        if (sideTwo >= sideThree ){
            b = sideTwo;
            a = sideThree;
        } else {
            a = sideTwo;
            b = sideThree;
        }
    } else if(sideTwo >= sideOne && sideTwo >= sideThree){
        c = sideTwo;
        if (sideThree >= sideOne ){
            b = sideThree;
            a = sideOne;
        } else {
            a = sideThree;
            b = sideOne;
        }
    } else if(sideThree >= sideOne && sideThree >= sideTwo) {
        c = sideThree;
        if (sideTwo >= sideOne ){
            b = sideTwo;
            a = sideOne;
        } else{
            a = sideTwo;
            b = sideOne;
        }
    }

    //determine if values make a triangle
    if(((a+b)<=c)||(a<=0||b<=0||c<=0)){
        cout << "Values do not make a triangle" << endl;
        return 1;
    } else {
        if(fabs(pow(a,2)+pow(b,2)-pow(c,2)) <= TOLERANCE){
            cout << "This triangle is a right triangle" << endl;
        } else if(pow(a,2)+pow(b,2) > pow(c,2) ){
            cout << "This triangle is an acute triangle" << endl;
        } else{
            cout << "This triangle is an obtuse triangle" << endl;
        }
    }

    //print out three sides in increasing order
    cout << "The sides in increasing order are: "<< a << " " << b << " "<< c << endl;

    //determine perimeter
    double perimeter = a+b+c;
    cout << "The perimeter is: " << perimeter << endl;

    //determine area
    double area;
    double semiPerimeter = perimeter/2;
    area = sqrt(semiPerimeter*(semiPerimeter-a)*(semiPerimeter-b)*(semiPerimeter-c));
    cout << "The area is: " << area << endl;
    return 0;
}
