#include <iostream>

/*
Author: Alexander Roth
Date: 09-13-2026
Purpose: This program is a simple BMI calculator
that prompts the user for their gender, height, weight, and age.
then calculates outputs the number of chocolate bars that should be
consumed to maintain their ideal weight.
*/

using namespace std;
/* Wanted to be able to just run the gender boolean logic once per iteration
since I needed it inside the calculateBMI function and for some of the copy in the main function
I got curious if c++ allowed for structured data types like C# and Javascript do.
https://www.w3schools.com/cpp/cpp_structs.asp
*/
struct UserData {
    int age;
    double height;
    double weight;
    char gender;
    bool isMale;
    bool isFemale;
};

int getValidAgeInput() {
    // Grabs the user's input, handles invalid input and returns the valid integer
    int input;
    cout << "Please enter your age: ";
    cin >> input;
    while (cin.fail() || input <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid positive whole number for age: ";
        cin >> input;
    }
    return input;
}

double getValidHeightInput() {
    // Grabs the user's input, handles invalid input and returns the valid double
    double input;
    cout << "Please enter your height in inches: ";
    cin >> input;
    while (cin.fail() || input <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid positive number for height: ";
        cin >> input;
    }
    return input;
}

double getValidWeightInput() {
    // Grabs the user's input, handles invalid input and returns the valid double
    double input;
    cout << "Please enter your weight in pounds: ";
    cin >> input;
    while (cin.fail() || input <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid positive number for weight: ";
        cin >> input;
    }
    return input;
}

char getValidGenderInput() {
    // Grabs the user's input, handles invalid input and returns the valid character
    char input;
    cout << "Please enter your gender (M/F): ";
    cin >> input;
    while (input != 'M' && input != 'F' && input != 'm' && input != 'f') {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter 'M' for male or 'F' for female: ";
        cin >> input;
    }
    return input;
}

char getValidUserChoice() {
    // Grabs the user's input, handles invalid input and returns the valid character
    char input;
    cout << "Do you want to calculate another BMI? (y/n): "; 
    cin >> input;
    while(input != 'y' && input != 'Y' && input != 'n' && input != 'N') {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Please enter 'y' or 'n': ";
        cin >> input;
    }
    return input;
}

double calculateBMI(UserData& user) {
    // BMI calculation based on the following formulas:
    // For males: 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age)
    // For females: 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age)

    if (user.isMale) {
        return 66 + (6.3 * user.weight) + (12.9 * user.height) - (6.8 * user.age);
    }
    if (user.isFemale) {
        return 655 + (4.3 * user.weight) + (4.7 * user.height) - (4.7 * user.age);
    }
    return 0;
}

    int main() {

    char userChoice;
    double bmi; 
    
    do {
        cout << "Welcome to the BMI Calculator!" << endl;
        UserData user;
        user.age = getValidAgeInput();
        user.height = getValidHeightInput();
        user.weight = getValidWeightInput();
        user.gender = getValidGenderInput();
        user.isMale = (user.gender == 'M' || user.gender == 'm');
        user.isFemale = (user.gender == 'F' || user.gender == 'f');
        bmi = calculateBMI(user);
        if (user.isMale) {
            cout << "His BMI is: " << bmi << endl;
        } else if (user.isFemale) {
            cout << "Her BMI is: " << bmi << endl;
        } else {
            // This case should never happen due to input validation
            // however I added it just in case to handle any unexpected scenarios.
            cout << "Your BMI is: " << bmi << endl;
        }
        cout << "Thats about " << bmi/230 << " chocolate bars." << endl;
        userChoice = getValidUserChoice();
        cout << endl;
    } while (userChoice == 'y' || userChoice == 'Y');

 
}
