#include <bits/stdc++.h>
using namespace std;
int solve_1(int i, int j, vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    // base case
    if (i == 0)
        return matrix[0][j];

    // try out all possibility
    int up = matrix[i][j] + solve_1(i - 1, j, matrix);
    int leftDiagonal = 1e9;
    if (j >= 1)
        leftDiagonal = matrix[i][j] + solve_1(i - 1, j - 1, matrix);

    int rightDiagonal = 1e9;
    if (j + 1 < m)
        rightDiagonal = matrix[i][j] + solve_1(i - 1, j + 1, matrix);

    return min(up, min(leftDiagonal, rightDiagonal));
}
int solve_2(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    int n = matrix.size();
    int m = matrix[0].size();
    // base case
    if (i == 0)
        return matrix[0][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    // try out all possibility
    int up = matrix[i][j] + solve_1(i - 1, j, matrix);
    int leftDiagonal = 1e9;
    if (j >= 1)
        leftDiagonal = matrix[i][j] + solve_2(i - 1, j - 1, matrix, dp);

    int rightDiagonal = 1e9;
    if (j + 1 < m)
        rightDiagonal = matrix[i][j] + solve_2(i - 1, j + 1, matrix, dp);

    return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
}
int solve_3(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // base case
    for (int j = 0; j < m; j++)
        dp[0][j] = matrix[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // try out all possibility
            int up = matrix[i][j] + dp[i-1][j];
            int leftDiagonal = 1e9;
            if (j >= 1)
                leftDiagonal = matrix[i][j] + dp[i-1][j-1];

            int rightDiagonal = 1e9;
            if (j + 1 < m)
                rightDiagonal = matrix[i][j] + dp[i-1][j+1];

            dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
        }
    }
        int mini = 1e9;
    for (int j = 0; j < m; j++)
    {
        mini = min(mini, dp[n - 1][j]);
    }
    return mini;
}
int solve_4(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m, -1);
    // base case
    for (int j = 0; j < m; j++)
        prev[j] = matrix[0][j];

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(m, -1);
        for (int j = 0; j < m; j++)
        {
            // try out all possibility
            int up = matrix[i][j] + prev[j];
            int leftDiagonal = 1e9;
            if (j >= 1)
                leftDiagonal = matrix[i][j] + prev[j-1];

            int rightDiagonal = 1e9;
            if (j + 1 < m)
                rightDiagonal = matrix[i][j] + prev[j+1];

            curr[j] = min(up, min(leftDiagonal, rightDiagonal));
        }
        prev=curr;
    }
    int mini = 1e9;
    for (int j = 0; j < m; j++)
    {
        mini = min(mini, prev[j]);
    }
    return mini;
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    // int n = matrix.size();
    // int m = matrix[0].size();
    // int mini = 1e9;
    // for (int j = 0; j < m; j++)
    // {
    //     mini = min(mini, solve_1(n - 1, j, matrix));
    // }
    // return mini;

    // int n = matrix.size();
    // int m = matrix[0].size();
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // int mini = 1e9;
    // for (int j = 0; j < m; j++)
    // {
    //     mini = min(mini, solve_2(n - 1, j, matrix,dp));
    // }
    // return mini;


    return solve_4(matrix);
}
// https://leetcode.com/problems/minimum-falling-path-sum/submissions/1268805270/
int main()
{

    return 0;
}