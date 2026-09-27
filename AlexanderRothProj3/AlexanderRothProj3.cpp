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

int getUserMove(bool isFirstTurn) {
    int move;
    if (isFirstTurn) {
        cout << "Enter the number of sticks you wish to pick (1-3): ";
    }
    else {
        cout << "Your Turn! Enter the number of sticks you wish to pick (1-3): ";
    }

    while (!(cin >> move) || (move < 1 || move > 3)) {
        cout << "Invalid input. Please enter a number between 1 and 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return move;
}

int getComputerMove(int toothpicksRemaining , int userMove) {
    int move = (toothpicksRemaining - 1) % 4;
    if (move == 0) {
        move = 1;
    }
    return move;
}

bool continueGame() {
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
        bool isFirstTurn = true;
        int toothpicksRemaining = 23;
        while (toothpicksRemaining > 0) {
            int userMove = getUserMove(isFirstTurn);
            isFirstTurn = false;
            toothpicksRemaining -= userMove;
            if (toothpicksRemaining < 0) {
                cout << "You withdrew the last toothpick. You lose!" << endl;
                break;
            }
            cout << "You picked " << userMove << " stick(s) "  << toothpicksRemaining << " left" << endl;
            int computerMove = getComputerMove(toothpicksRemaining, userMove);
            cout << "Computer withdraws " << computerMove << " toothpicks." << endl;
            toothpicksRemaining -= computerMove;
            if (toothpicksRemaining < 0) {
                cout << "The computer withdrew the last toothpick. You win!" << endl;
                break;
            }
            cout << "Computer picked " << computerMove << " stick(s) "  << toothpicksRemaining << " left" << endl;
        }
    } while (continueGame());
    return 0;
}