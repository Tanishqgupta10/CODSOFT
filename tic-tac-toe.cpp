#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void printBoard(const vector<vector<char>>& board);
bool placeMark(vector<vector<char>>& board, int row, int col, char mark);
bool checkWin(const vector<vector<char>>& board, char mark);
bool isBoardFull(const vector<vector<char>>& board);

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // 3x3 board initialized with spaces
    char currentPlayer = 'X'; // Start with player 'X'
    int row, col;
    bool gameWon = false;

    while (true) {
        printBoard(board);
        
        // Get the player's move
        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
        cin >> row >> col;

        // Validate the move
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Place the mark on the board
        placeMark(board, row, col, currentPlayer);

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameWon = true;
            break;
        }

        // Check if the board is full
        if (isBoardFull(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

void printBoard(const vector<vector<char>>& board) {
    cout << "  0 1 2" << endl; // Column numbers
    for (int i = 0; i < 3; ++i) {
        cout << i << " "; // Row number
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

bool placeMark(vector<vector<char>>& board, int row, int col, char mark) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = mark;
        return true;
    }
    return false;
}
bool checkWin(const vector<vector<char>>& board, char mark) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) {
            return true;
        }
    }
    
    // Check columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == mark && board[1][j] == mark && board[2][j] == mark) {
            return true;
        }
    }
    
    // Check diagonals
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) {
        return true;
    }
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) {
        return true;
    }
    
    return false;
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
