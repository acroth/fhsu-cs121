#include <iostream>
#include <string>
#include <limits> // provides the numeric_limits for input validation

/*
Author: Alexander Roth
Date: 08-26-2026
Purpose: This program calculates the total value of coins entered by the user. It prompts the user for the number of quarters, dimes, nickels, and pennies. Validates the input to ensure it's an integer and non-negative, then computes and displays the total value.
*/

using namespace std;
/*
Function that reads and validates the user's input. Passes the coin name as a parameter and only returns when a valid input is received.
*/
/*
I'm using a reference declaration(&) for the coin name after looking how c++ handles string parameters. This is so the function just reads the string without making a new copy in memory for each use. Since strings aren't primitive data types this seemed like a good idea.

here are my references:
https://codehs.com/tutorial/david/passing-values-to-functions-in-c
https://en.cppreference.com/cpp/language/reference
*/
int readValidInput(const string& COIN_NAME) {
    int input;
    cout << "Enter the number of " << COIN_NAME << ": ";
    while (!(cin >> input) || input < 0) {
        // Clear the error
        cin.clear();
        // adding this because I was getting weird behavior when testing with an invalid input. Found that this is because the input still contained the invalid characters. This clears that so the next input can be read. 
        //https://medium.com/@ryan_forrester_/understanding-and-using-cin-ignore-in-c-09ead6df053f
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a non-negative number for " << COIN_NAME << ": ";
    }
    return input;
}

int main() {
    // Initialize variables for coin counts and total value and loop through to get user input for each coin type
    int quarters, dimes, nickels, pennies;
    double total;
    int loopCounter;
    for (loopCounter = 0; loopCounter < 4; loopCounter++) {
        if (loopCounter == 0) {
            quarters = readValidInput("quarters");
        } else if (loopCounter == 1) {
            dimes = readValidInput("dimes");
        } else if (loopCounter == 2) {
            nickels = readValidInput("nickels");
        } else if (loopCounter == 3) {
            pennies = readValidInput("pennies");
        }
    }
    // Calculate the total value of the coins, output to console and end the program
    total = (quarters * 0.25) + (dimes * 0.10) + (nickels * 0.05) + (pennies * 0.01);
    cout << "The total value of the coins is: $" << total << endl;
    return 0;
}