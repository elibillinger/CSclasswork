/* CSCI 261 Lab 6A: Polar to Cartesian
 *
 * Author: Eli Billinger
 *
 * USING 3 SKIP DAYS 2 REMAINING
 * Create a Pass by Value and Pass by Reference functions
 */
#include <iostream>
#include <cmath>
using namespace std;

struct CartesianPoint {
    double x;
    double y;
};
struct PolarPoint {
    double radius;
    double theta;
};
CartesianPoint polarToCartesianPBV(const PolarPoint point) {
CartesianPoint newPoint;
newPoint.x = point.radius * cos(point.theta) ;
newPoint.y = point.radius * sin(point.theta);
return newPoint;
}

PolarPoint cartesianToPolarPBV(const CartesianPoint point){
PolarPoint newPoint;
newPoint.radius =sqrt(pow(point.x,2)+pow(point.y,2));
newPoint.theta = atan(point.x/point.y);
return newPoint;
}

void polarToCartesianPBR(const double radius, const double angle, double& xCoord, double& yCoord){
    xCoord = radius * cos(angle);
    yCoord = radius * sin(angle);
}
void cartesianToPolarPBR( const double xCoord, const double yCoord, double& radius, double& angle){
    angle = atan(xCoord/yCoord);
    radius = sqrt(pow(xCoord,2) + pow(yCoord,2));
}
int main() {
    int choice;
    double xCoord, yCoord, radius , angle;
    cout << "Do you want to convert from cartesian to polar (1) or polar to cartesian (2) (input 1 or 2)" << endl;
    cin >> choice;
    if(choice == 1){
        // get correct data from user
        CartesianPoint point;
        cout << "Enter x value" << endl;
        cin >> point.x;
        cout << "Enter y value" << endl;
        cin >> point.y;
        xCoord = point.x;
        yCoord = point.y;
        //output and call functions both PBV and PBR
        cout << "( " << point.x << " , "  << point.y << " ) -->";
        PolarPoint newPoint = cartesianToPolarPBV(point);
        cout << "( " << newPoint.radius << " , " << newPoint.theta << " )" << endl;
        cout << "( " << xCoord << " , "  << yCoord << " ) -->";
        cartesianToPolarPBR(xCoord, yCoord, radius, angle);
        cout << "( " << radius << " , " << angle << " )" << endl;

    } else {
        // get correct data from user
        PolarPoint point;
        cout << "Enter radius value" << endl;
        cin >> point.radius;
        cout << "Enter theta value (radians)" << endl;
        cin >> point.theta;
        radius = point.radius;
        angle = point.theta;
        //output and call functions both PBV and PBR
        cout << "( " << point.radius << " , "  << point.theta << " ) -->";
        CartesianPoint newPoint = polarToCartesianPBV(point);
        cout << "( " << newPoint.x << " , " << newPoint.y << " )" << endl;
        cout << "( " << radius << " , "  << angle << " ) -->";
        polarToCartesianPBR(radius, angle, xCoord, yCoord);
        cout << "( " << xCoord << " , " << yCoord << " )" << endl;

    }

    return 0;
}
