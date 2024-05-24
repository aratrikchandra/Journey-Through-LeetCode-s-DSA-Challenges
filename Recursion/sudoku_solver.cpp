#include <bits/stdc++.h>
using namespace std;
bool isValid(int row, int col, char c, vector<vector<char>> &board)
{
    for (int i = 0; i <= 8; i++)
    {
        // checking the same row
        if (board[row][i] == c)
            return false;
        // checking the same col
        if (board[i][col] == c)
            return false;

        // checking the same 3*3 submatrix
        if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c)
            return false;
    }
    return true;
}
bool solve(vector<vector<char>> &board)
{
    int n = board.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '.')
            { // empty cell
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(i, j, c, board))
                    {
                        // put the item in the board
                        board[i][j]=c;
                        if(solve(board)==true)
                        return true;

                        board[i][j]='.';
                    }
                }
                // control comes here means we can't put any of 1-9 in the empty cell
                return false;
            }
        }
    }
    // control comes here means we traversed the entire board
    return true;
}
void solveSudoku(vector<vector<char>> &board){
    solve(board);
}
int main()
{
    vector<vector<char>> board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};

    solveSudoku(board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    return 0;
}

// https://leetcode.com/problems/sudoku-solver/submissions/1225867099/