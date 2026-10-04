#include <iostream>
#include <limits>

/* 
Author: Alexander Roth
Date: 09-26-2026
Purpose: Project 3, Game of "23"
The game of "23" is a two-player game that begins with a pile of 23 toothpicks. Players take
turns, withdrawing either 1, 2, or 3 toothpicks at a time. The player to withdraw the last
toothpick loses the game. Write a human vs. computer program that plays "23". The human
should always move first. 
*/

using namespace std;

int getUserMove(bool isFirstTurn, int toothpicksRemaining) {
    // Prompt the user for their move and validate it
    int move;
    if (isFirstTurn) {
        cout << "Enter the number of sticks you wish to pick (1-3): ";
    }
    else {
        cout << "Your Turn! Enter the number of sticks you wish to pick (1-3):";
    }

    while (!(cin >> move) || (move < 1 || move > 3) || (move > toothpicksRemaining)) {
        if (move > toothpicksRemaining) {
            cout << "You cannot pick more sticks than are remaining. Please pick again:  ";
        }
        else {
            cout << "Wrong Number of sticks. Please pick 1, 2, or 3 sticks: ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return move;
}

int getComputerMove(int toothpicksRemaining , int userMove) {
    // Calculate the computer's move based on the remaining toothpicks and the user's move
    int move = (toothpicksRemaining - 1) % 4;
    return move;
}
bool continueGame() {
    // Prompt the user to continue playing the game and validate their input
    char choice;
    cout << "Do you want to play again? (y/n): ";
    while (!(cin >> choice) || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
        cout << "Invalid input. Please enter 'y' or 'n': ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (choice == 'n' || choice == 'N')
        cout << "Thank you for playing the game of 23!" << endl;
    return (choice == 'y' || choice == 'Y');
}


int main() {
    cout << "Lets play a game of 23!" << endl;
    do {
        //  loop number check for proper message display
        bool isFirstTurn = true;
        int toothpicksRemaining = 23;
        // Main game loop
        while (toothpicksRemaining > 0) {
            int userMove = getUserMove(isFirstTurn, toothpicksRemaining);
            isFirstTurn = false;
            toothpicksRemaining -= userMove;
            if (toothpicksRemaining <= 0) {
                cout << "You picked the last stick. You lose!" << endl;
                break;
            }
            cout << "You picked " << userMove << " stick(s) "  << toothpicksRemaining << " left" << endl;
            int computerMove = getComputerMove(toothpicksRemaining, userMove);
            toothpicksRemaining -= computerMove;
            if (toothpicksRemaining <= 0) {
                cout << "The computer picked the last stick. You win!" << endl;
                break;
            }
            cout << "Computer picked " << computerMove << " stick(s) "  << toothpicksRemaining << " left" << endl;
        }
    } while (continueGame());
    return 0;
}