#include <iostream>
#include <cassert>
#include <iomanip>

/*
Author: Alexander Roth
Date: 10-20-2026
Purpose: Practice reading and writing to a one-dimensional array
*/

void userInput(int array[], int size);
char grade(int score);
void printGradeMatrix(int array[], int size);

int main(){
    const int SIZE = 5;
    int scores[SIZE];
    userInput(scores, SIZE);
    printGradeMatrix(scores, SIZE);

    return 0;

}

void userInput(int array[], int size) {
    assert(size > 0);
    for (int i = 0; i < size; i++) {
        std::cout << "Enter score for student " << i + 1 << ": ";
        std::cin >> array[i];
    }
}
char grade(int score) {
    //precondition to ensure score is within the valid range (0-100)
    assert(score >= 0 && score <= 100);

    //Lookup array for grades, indexed by score / 10
    char grade_lookup[] = {
        'F', 'F','F','F','F','F','D','C','B','A','A'
    };
    //Dividing by 10 for numbers between 0 and 100 will return the corresponding grade
    //score is an int so division result is truncated (ex: 75/10 = 7.5 -> grade_lookup[7])
    return grade_lookup[score / 10];
}

void printGradeMatrix(int array[], int size) {
    assert(size > 0);
   // Print ASCII table header
    std::cout << "\n+---------+-------+-------+\n";
    std::cout << "| Student | Score | Grade |\n";
    std::cout << "+---------+-------+-------+\n";

    // Print rows directly from the array
    for (int i = 0; i < size; i++) {
        std::cout << "| " << std::setw(5) << i + 1
                  << " | " << std::setw(5) << array[i] 
                  << " | " << std::setw(5) << grade(array[i]) 
                  << " |\n";
    }

    // Print table footer
    std::cout << "+---------+-------+-------+\n";
}