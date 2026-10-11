#include <iostream>
#include <cassert>
#include <limits>
/* 
Author: Alexander Roth
Date: 08-04-2026
Purpose: Write a program to take a depth in kilometers inside the earth as input data; calculate and display
the temperature at this depth in both degrees Celsius and degree Fahrenheit.
*/

using namespace std;
// Function prototypes
void print_introduction();
double celsius_at_depth(double depth);
double celsius_to_fahrenheit(double celsius);
void print_conclusion(double depth);


int main() {
    print_introduction();
    char userChoice;

    do {
        
        double depth;
        cout << "Enter the depth in kilometers: ";
        cin >> depth;
        // Validate depth input
        while (depth < 0 || cin.fail()) {
            cout << "Invalid input. Please enter a positive number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> depth;
        }
        print_conclusion(depth);
        cout << "Do you want to do it again? (Y/N): ";
        cin >> userChoice;
        // Validate user choice
        while (userChoice != 'y' && userChoice != 'Y' && userChoice != 'n' && userChoice != 'N') {
            cout << "Invalid input. Please enter 'Y' or 'N': ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> userChoice;
        }
    } while (userChoice == 'y' || userChoice == 'Y');
    
    return 0;
}
// Function definitions
void print_introduction() {
    cout << "Hello! The program will tell you the temperature of the earth at any depth" << endl;
};

double celsius_at_depth(double depth) {
    assert(depth >= 0);
    return 10 * depth + 20;
}

double celsius_to_fahrenheit(double celsius) {
    // Can't go lower than absolute zero
    assert(celsius >= -273.15);
    return 1.8 * celsius + 32;
}

void print_conclusion(double depth) {
    // Runs the calculation functions and outputs the results
    assert(depth >= 0);
    double celsius = celsius_at_depth(depth);
    double fahrenheit = celsius_to_fahrenheit(celsius);
    // Can't go lower than absolute zero
    assert(fahrenheit >= -459.67);
    cout << "The temperature at " << depth << " KM is " << celsius << " in Celsius and " << fahrenheit << " in Fahrenheit" << endl;
}
