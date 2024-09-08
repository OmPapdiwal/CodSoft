#include <iostream>
#include <vector>

using namespace std;

const int BOARD_SIZE = 3;
const char EMPTY_SLOT = ' ';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

void displayBoard(const vector<vector<char> >& board) {
    cout << "\nCurrent Board:\n";
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            cout << board[row][col];
            if (col < BOARD_SIZE - 1) cout << " | ";
        }
        cout << "\n";
        if (row < BOARD_SIZE - 1) cout << "--------\n";
    }
    cout << endl;
}

bool checkWinner(const vector<vector<char> >& board, char player) {
    // Check for a winning line in rows and columns
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check for a winning line in diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool isBoardFull(const vector<vector<char> >& board) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (board[row][col] == EMPTY_SLOT) {
                return false;
            }
        }
    }
    return true;
}

bool isValidMove(const vector<vector<char> >& board, int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == EMPTY_SLOT;
}

void startGame() {
    vector<vector<char> > board(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY_SLOT));
    char currentPlayer = PLAYER_X;
    int row, col;
    bool gameFinished = false;

    while (true) {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", it's your turn.\n";
        cout << "Enter your move (row and column): ";
        cin >> row >> col;

        // Convert to zero-based index
        row--;
        col--;

        if (!isValidMove(board, row, col)) {
            cout << "Invalid move. Please try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWinner(board, currentPlayer)) {
            displayBoard(board);
            cout << "Congratulations Player " << currentPlayer << "! You have won!\n";
            gameFinished = true;
            break;
        }

        if (isBoardFull(board)) {
            displayBoard(board);
            cout << "The game is a draw!\n";
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    char replay;
    cout << "Would you like to play again? (y/n): ";
    cin >> replay;

    if (replay == 'y' || replay == 'Y') {
        startGame(); // Restart the game
    }
}

int main() {
    startGame();
    return 0;
}

