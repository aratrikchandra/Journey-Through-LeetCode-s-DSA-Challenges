#include <bits/stdc++.h>
using namespace std;
bool solve(int ind, int row, int col, vector<vector<int>> &visited, vector<vector<char>> &board, int n, int m, string word)
{
    // base case
    if (ind == word.size()-1)
        return true;

    int dr[] = {1, 0, 0, -1};
    int dc[] = {0, -1, 1, 0};

    // exploring four directions
    for (int i = 0; i < 4; i++)
    {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visited[newRow][newCol])
        {
            // check if the next call actually matches the next char of word
            if (board[newRow][newCol] == word[ind + 1])
            {
                visited[newRow][newCol] = 1;
                if (solve(ind + 1, newRow, newCol, visited, board, n, m, word) == true)
                    return true;
                visited[newRow][newCol] = 0;
            }
        }
    }
    return false;
}
bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[0])
            { // board(i,j) can be a strating point
                visited[i][j] = 1;
                if (solve(0, i, j, visited, board, n, m, word) == true)
                    return true;
                visited[i][j] = 0;
            }
        }
    }
    return false;
}
int main()
{

    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout<<exist(board,word);
    return 0;
}

// https://leetcode.com/problems/word-search/submissions/1225556049/