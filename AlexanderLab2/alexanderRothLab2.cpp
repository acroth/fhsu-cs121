#include <iostream>
/*
Author: Alexander Roth
Date: 09-13-2026
Purpose: This program showcases the use of a do-while loop to continuously
prompt a user for input until they enter a specific input to exit the loop/program.
*/

using namespace std;


// Re-using some of my knowledge gained on lab 1 for input validation.
// function to ensure the user enters a valid choice for continuing or not
// only allowing 'y', 'Y', 'n', or 'N' as valid inputs
bool isValidUserChoice(char choice) {
    return (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N');
}

int getValidNumberInput() {
    // Grabs the user's input, handles invalid input and returns the valid integer
    int input;
    cout << "Please enter a number: ";
    cin >> input;
    /*cin.fail() checks if the input stream is in an error state.
    in this case I want to ensure I catch if the user enters a non integer
    if they do, I reset the stream and prompt them to enter again 
    until they enter a valid integer.
    */
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid whole number: ";
        cin >> input;
    }
    return input;
}
char getValidUserChoice() {
    // Grabs the user's input, handles invalid input and returns the valid character
    char input;
    cout << "Do you want to enter another number? (y/n): "; 
    cin >> input;
    while(!isValidUserChoice(input)) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Please enter 'y' or 'n': ";
        cin >> input;
    }
    return input;
}

int main() {

int numberInput;
char userChoice;

do {
    numberInput = getValidNumberInput();
    
    if (numberInput <= 0) {
        cout << "The number is non-positive." << endl;
    } else {
        cout << "The number is positive." << endl;
    }
    userChoice = getValidUserChoice();
    
} while (userChoice == 'y' || userChoice == 'Y');
cout << "Goodbye!" << endl;

}
