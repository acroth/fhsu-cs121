#include <iostream>
/* 
Author: Alexander Roth
Date: 10-11-2026
Purpose: The objective of this project is to create a simple number-guessing game. 
The game will generate a random number, and the player will have a limited number of guesses to guess the correct number.
*/

const int MAX_GUESSES = 3;
int numberToGuess;
int numGuesses;


void startGame();
int generateRandomNumber(int min, int max);
bool makeGuess(int guess, int& numGuesses);
void printStatistics(int numGuesses);

int main(){
    startGame();

    bool won = false;
    int guess;
    while (!won && ::numGuesses < MAX_GUESSES) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        won = makeGuess(guess, ::numGuesses);
    }
    if (won) {
        std::cout << "You win!" << std::endl;
    } else {
        std::cout << "You lose!" << std::endl;
    }
    printStatistics(::numGuesses);
    return 0;
}

void startGame() {
    // Initializes the game state, generating the random number and setting the guess count
    ::numGuesses = 0;
    ::numberToGuess = generateRandomNumber(1, 100);
    std::cout << "Game is started!" << std::endl;
}

int generateRandomNumber(int min, int max) {
    // Logic to generate the random number between the min and max values
    std::srand(std::time(0));
    return std::rand() % (max - min + 1) + min;
}

bool makeGuess(int guess, int& numGuesses) {
    // Bump guess count and return the guess
    numGuesses++;
    return guess == ::numberToGuess;
}
void printStatistics(int numGuesses) {
    // Display info to the user about their performance
    std::cout << "You've made " << numGuesses << " guesses. The number was " << ::numberToGuess  << std::endl;

}