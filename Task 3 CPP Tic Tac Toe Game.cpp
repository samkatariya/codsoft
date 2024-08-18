#include <iostream>
#include <vector>

using namespace std;

// Function to display the current state of the board
void displayBoard(const vector<vector<char>>& board) {
    cout << "Current Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------\n";
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false; // Found an empty cell, not a draw
        }
    }
    return true; // No empty cells, it's a draw
}

// Function to play the game
void playGame() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameOngoing = true;

    while (gameOngoing) {
        displayBoard(board);
        int row, col;

        // Player input
        cout << "Player " << currentPlayer << ", enter your move (row and column from 1 to 3): ";
        cin >> row >> col;

        // Adjust for 1-based indexing
        row -= 1; // Convert to 0-based index
        col -= 1; // Convert to 0-based index

        // Validate input
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move, try again.\n";
            continue;
        }

        // Update the board
        board[row][col] = currentPlayer;

        // Check for win or draw
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            gameOngoing = false;
        } else if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            gameOngoing = false;
        } else {
            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

// Main function
int main() {
    char playAgain;

    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!\n";
    return 0;
}