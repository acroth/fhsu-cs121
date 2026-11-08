#include <iostream>
#include <cassert>
#include <limits>
#include <iomanip>
#include <cstdlib>
/* 
Author: Alexander Roth
Date: 10-23-2026
Purpose: Create multiplayer tic-tac-toe game using 2D arrays
*/

using namespace std;

void initializeBoard(char board[3][3]);
void printBoard(char board[3][3]);
bool checkWin(char board[3][3], int row, int col, char player);
bool checkDraw(int moveCount);
void makeMove(char board[3][3], char currentPlayer, int &moveCount, int &row, int &col);
void clearConsole();


int main(){
    char board[3][3];
    initializeBoard(board);
    char currentPlayer = 'X';
    // Variables to track moves for cleaner win/draw logic
    int moveCount = 0;
    int row = 0, col = 0;
    bool isGameOver = false;


    do
    {   
        clearConsole();
        cout << "\n\n\n=================================\n";
        cout << "       TIC-TAC-TOE  \n";
        cout << "=================================\n\n\n";
        cout << "Player 1: X | Player 2: O\n";
        cout << "Coordinates use 0, 1, or 2 for Row and Column.\n";
        printBoard(board);
        makeMove(board, currentPlayer, moveCount, row, col);
        if(checkWin(board,row,col, currentPlayer))
        {
            clearConsole();
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            isGameOver = true;
        }
        else if (checkDraw(moveCount))
        {
            clearConsole();
            printBoard(board);
            cout << "It's a draw!\n";
            isGameOver = true;
        }
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    } while (!isGameOver);
    

}

void initializeBoard(char board[3][3])
// Set all elements of the board to empty spaces to start the game
// Empty board values are spaces
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[3][3]){
    cout << "\n       0   1   2\n";
    cout << "     -------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "   " << i << " |";
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " |";
        }
        cout << "\n     -------------\n";
    }
    cout << endl;
    cout << endl;
}

void makeMove(char board[3][3], char currentPlayer, int &moveCount, int &row, int &col)
{
    assert(currentPlayer == 'X' || currentPlayer == 'O');
    assert(moveCount >= 0 && moveCount <= 9);

    cout << "Player " << currentPlayer << "'s turn.\n";
    cout << "Enter your move (row and column): ";
    // Validate user input, ensuring it's within bounds and the space is available
    while (!(cin >> row >> col) || row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
    {
        cout << "Invalid move. Please enter integers between 0 and 2 on an unused space.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    assert(row >= 0 && row < 3);
    assert(col >= 0 && col < 3);
    assert(board[row][col] == ' ');

    board[row][col] = currentPlayer;
    moveCount++;
}
bool checkWin(char board[3][3], int row, int col, char player)
{
    assert(player == 'X' || player == 'O');
    assert(row >= 0 && row < 3);
    assert(col >= 0 && col < 3);

    /*
       Rather than looping through the entire board everytime I've opted to track the most recent move
       this allows me to just check the relevant rows, columns, and diagonals
    */
   bool hasWonRow = (board[row][0] == player && board[row][1] == player && board[row][2] == player);
   bool hasWonCol = (board[0][col] == player && board[1][col] == player && board[2][col] == player);
   bool hasWonDiag = (row == col && board[0][0] == player && board[1][1] == player && board[2][2] == player);
   bool hasWonReverseDiag = (row + col == 2 && board[0][2] == player && board[1][1] == player && board[2][0] == player);

    if(hasWonRow || hasWonCol || hasWonDiag || hasWonReverseDiag)
        return true;

    return false;
}
bool checkDraw(int moveCount)
{
    // Move count can't be more than 9 so if players haven't won after 9 moves, it's a draw
    assert(moveCount >= 0 && moveCount <= 9);
    if(moveCount == 9)
        return true;
    return false;
}
void clearConsole()
{
    // Trying to make user visuals a little more streamlined
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}