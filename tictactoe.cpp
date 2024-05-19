#include <iostream>
#include <vector>
using namespace std;

void initializeBoard(vector<vector<char>> &board)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const vector<vector<char>> &board)
{
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i)
    {
        cout << "| ";
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool checkWin(const vector<vector<char>> &board, char player)
{

    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }

    return false;
}

bool checkTie(const vector<vector<char>> &board)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

void playerMove(vector<vector<char>> &board, char player)
{
    int row, col;
    cout << "Player " << player << ", enter your move (row and column): ";
    cin >> row >> col;

    while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ')
    {
        cout << "Invalid move! Try again: ";
        cin >> row >> col;
    }

    board[row - 1][col - 1] = player;
}

int main()
{
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    cout << "Welcome to Tic Tac Toe Game!\n";
    initializeBoard(board);

    while (true)
    {
        displayBoard(board);
        playerMove(board, currentPlayer);

        if (checkWin(board, currentPlayer))
        {
            displayBoard(board);
            cout << "P  " << currentPlayer << " Wins!\n";
            break;
        }
        else if (checkTie(board))
        {
            displayBoard(board);
            cout << "It's a Tie!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
    }
}