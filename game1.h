#include <iostream>
#include <vector>
#include <string>

using namespace std;
namespace game1{

// Function to print the board
void printBoard(const vector<string>& board) {
    for (int i = 0; i < 3; ++i) {
        cout << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if (i != 2) {
            cout << "---------" << endl;
        }
    }
}

// Function to check if a player has won
bool checkWin(const vector<string>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal 1
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal 2
    }

    return false;
}

int main() {
    vector<string> board(3, "   "); // Initialize an empty board
    bool gameOver = false;
    char currentPlayer = 'X';

    while (!gameOver) {
        // Print the board
        printBoard(board);

        // Get the player's move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        }

        // Check if the board is full (tie)
        bool boardFull = true;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    boardFull = false;
                    break;
                }
            }
            if (!boardFull) {
                break;
            }
        }

        if (boardFull) {
            cout << "It's a tie!" << endl;
            gameOver = true;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Print the final board
    printBoard(board);

    return 0;
}
}
