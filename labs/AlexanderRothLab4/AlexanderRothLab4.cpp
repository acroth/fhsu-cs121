#include <iostream>
#include <cassert>
/*
Author: Alexander Roth
Date: 08-04-2026
Purpose: Writing User Defined Functions
The objective of this lab is to write user defined functions to calculate
the area of a circle and the volume of a sphere. Additionally, you will
practice writing proper preconditions and postconditions.
*/
using namespace std;
// Constant variable for PI (3.14159)
const double PI = 3.14159;
// function prototypes
double circleArea(double radius);
double sphereVolume(double radius);

int main() {
    double radius;
    cout << "Enter the radius: ";
    cin >> radius;
    cout << "Area of the circle: " << circleArea(radius) << endl;
    cout << "Volume of the sphere: " << sphereVolume(radius) << endl;
    return 0;
}

double circleArea(double radius) {
    // circleArea definition, takes radius as a parameter and outputs the circle's area
    // Precondition: radius is greater than or equal to 0
    assert(radius >= 0);
    double area = PI * radius * radius;
    // Postcondition: area is not negative
    assert(area >= 0);
    return area;
}

double sphereVolume(double radius) {
    // sphereVolume definition, takes radius as a parameter and outputs the sphere's volume
    // Precondition: radius is greater than or equal to 0
    assert(radius >= 0);
    double volume = (4.0/3.0) * PI * (radius * radius * radius);
    // Postcondition: volume is not negative
    assert(volume >= 0);
    return volume;
}