#include <bits/stdc++.h>
using namespace std;

// recursive approach
int solve_1(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid)
{
    // base case
    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    // try out all possible options
    int maxi = -1e9;
    // efficient way to represent 9 moves together
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = -1e9;
            // checking array out of bound
            if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
            {
                value = solve_1(i + 1, j1 + dj1, j2 + dj2, n, m, grid);
                if (j1 == j2)
                    value += grid[i][j1];
                else
                    value += grid[i][j1] + grid[i][j2];
            }
            maxi = max(maxi, value);
        }
    }
    return maxi;
}
// memoization
int solve_2(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    // base case
    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    // try out all possible options
    int maxi = -1e9;
    // efficient way to represent 9 moves together
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = -1e9;
            // checking array out of bound
            if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
            {
                value = solve_2(i + 1, j1 + dj1, j2 + dj2, n, m, grid, dp);
                if (j1 == j2)
                    value += grid[i][j1];
                else
                    value += grid[i][j1] + grid[i][j2];
            }
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}
// tabulation
int solve_3(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    // base case
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                // try out all possible options
                int maxi = -1e9;
                // efficient way to represent 9 moves together
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = -1e9;
                        // checking array out of bound
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                        {
                            value = dp[i + 1][j1 + dj1][j2 + dj2];
                            if (j1 == j2)
                                value += grid[i][j1];
                            else
                                value += grid[i][j1] + grid[i][j2];
                        }
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m-1];
}
// space optimization
int solve_4(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> front(m, vector<int>(m, -1));
    // base case
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                front[j1][j2] = grid[n - 1][j1];
            else
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        vector<vector<int>> curr(m, vector<int>(m, -1));
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                // try out all possible options
                int maxi = -1e9;
                // efficient way to represent 9 moves together
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = -1e9;
                        // checking array out of bound
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                        {
                            value = front[j1 + dj1][j2 + dj2];
                            if (j1 == j2)
                                value += grid[i][j1];
                            else
                                value += grid[i][j1] + grid[i][j2];
                        }
                        maxi = max(maxi, value);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front=curr;
    }
    return front[0][m-1];
}
int solve(int n, int m, vector<vector<int>> &grid)
{
    //    return solve_1(0,0,m-1,n,m,grid);
    // vector<vector<vector<int>>> dp(n,vector<vector<int>> (m, vector<int> (m,-1)));
    // return solve_2(0,0,m-1,n,m,grid,dp);

    return solve_4(n, m, grid);
}

// https://www.geeksforgeeks.org/problems/chocolates-pickup/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=chocolates-pickup
int main()
{

    return 0;
}