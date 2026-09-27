#include <iostream>
#include <limits>


/*
Author: Alexander Roth
Date: 09-26-2026
Purpose: Grade calculator program,
The objective of this lab is to develop a C++ program that allows users to enter grades and prints out to
the console the corresponding letter grades
*/

using namespace std;


double getUserGradeInput() {
    // Allowing for input of grades with decimal points
    double grade;
    cout << "Enter a grade (0-100): ";
    // input validation
    while (!(cin >> grade) || (grade < 0 || grade > 100)) {
        cout << "Invalid input. Please enter a grade between 0 and 100: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return grade;
}

char displayLetterGrade(double numericGrade) {
    /* Dropping the decimal part of the grade to determine the letter grade
    as part of the calculation. We allow for grades to be entered as decimal points,
    however the grade ranges are general buckets with hard whole number thresholds.

    Additionally, the default case should not be reachable due to the input validation in getUserGradeInput(),
    but I've included as a safeguard for unexpected values or an issue in the calculation.
    */
    switch (static_cast<int>(numericGrade / 10)) {
        case 10:
        case 9:
            return 'A';
        case 8:
            return 'B';
        case 7:
            return 'C';
        case 6:
            return 'D';
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
            return 'F';
        default:
            return '?';
    }
}

bool continuePrompt() {
    char choice;
    cout << "Do you want to enter another grade? (y/n): ";
    // input validation
    while (!(cin >> choice)){
        cout << "Invalid input. Please enter 'y' or 'n': ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // Display exit message if the user chooses not to continue
    if(choice == 'n' || choice == 'N')
        cout << "Thank you for using the grade calculator!" << endl;
    // Return a boolean value for the do-while loop condition
    return (choice == 'y' || choice == 'Y');
}


int main(){

    do {
        double grade = getUserGradeInput();
        cout << "The letter grade is: " << displayLetterGrade(grade) << endl;
    } while (continuePrompt());

    return 0;
}