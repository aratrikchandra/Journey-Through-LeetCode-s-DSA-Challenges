#include <bits/stdc++.h>
using namespace std;

// recursive approach
int solve_1(int i, int j, vector<vector<int>> &grid)
{
    // base case
    if (i == 0 && j == 0)
        return grid[0][0];

    int up = INT_MAX, left = INT_MAX;

    if (i > 0)
        up = grid[i][j] +solve_1(i - 1, j,grid);

    if (j > 0)
        left = grid[i][j]+ solve_1(i, j - 1,grid);

    return min(up ,left);
}
// meoization
int solve_2(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    // base case
    if (i == 0 && j == 0)
        return grid[0][0];
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = INT_MAX, left = INT_MAX;

    if (i > 0)
        up = grid[i][j] +solve_2(i - 1, j,grid,dp);

    if (j > 0)
        left = grid[i][j]+ solve_2(i, j - 1,grid,dp);

    return dp[i][j] = min(up ,left);
}
// tabulation
int solve_3(vector<vector<int>> &grid)
{
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 1e9));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            // base case
            if (i == 0 && j == 0)
            {
                dp[0][0] = grid[0][0];
                continue;
            }
            int up = INT_MAX, left = INT_MAX;

            if (i > 0)
                up = grid[i][j] +dp[i - 1][j];

            if (j > 0)
                left =grid[i][j]+ dp[i][j - 1];

            dp[i][j] = min(up, left);
        }
    }

    return dp[m - 1][n - 1];
}
// space optimization
int solve_4(vector<vector<int>> &grid)
{
        int m=grid.size();
    int n=grid[0].size();
    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {

            // base case
            if (i == 0 && j == 0)
            {
                curr[0] = grid[0][0];
                continue;
            }
            int up = INT_MAX, left = INT_MAX;

            if (i > 0)
                up =grid[i][j]+ prev[j];

            if (j > 0)
                left =grid[i][j]+ curr[j - 1];

            curr[j] = min(up ,left);
        }
        prev = curr;
    }

    return prev[n - 1];
}

int minPathSum(vector<vector<int>> &grid)
{
    // return solve_1(m-1,n-1);
    // vector<vector<int>> dp(m,vector<int> (n,-1));
    // return solve_2(m-1,n-1,dp);

    // return solve_3(m, n);
    // return solve_4(m, n);
}

// https://leetcode.com/problems/minimum-path-sum/submissions/1267455546/
int main()
{

    return 0;
}