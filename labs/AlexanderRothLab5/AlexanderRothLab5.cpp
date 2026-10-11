#include <iostream>
#include <cassert>
#include <limits>

/*
Author: Alexander Roth
Date: 10-11-2026
Purpose: The objective of this lab is to call functions from within other functions and passing parameters by-
reference. Program calculates the area of a rectangle.
*/

using namespace std;

double getLength();
double getWidth();
double calculateArea(const double& length, const double& width);


int main(){
    double length = getLength();
    double width = getWidth();
    double area = calculateArea(length, width);
    cout << "The area of the rectangle is: " << area << endl;
    return 0;
}

double getLength(){
    // Prompt the user to enter a length and return that value
    double length;
    cout << "Enter the length of the rectangle: ";
    // Validate input
    while (!(cin >> length)) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // Postcondition: length is positive
    assert(length > 0);
    return length;
}

double getWidth(){
    // Prompt the user to enter a width and return that value
    double width;
    cout << "Enter the width of the rectangle: ";
    // Validate input
    while (!(cin >> width)) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // Postcondition: width is positive
    assert(width > 0);
    return width;
}
double calculateArea(const double& length, const double& width){
    // Precondition: length and width are positive, a little redundant but just to be sure
    assert(length > 0 && width > 0); 
    return length * width;
}