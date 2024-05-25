#include <bits/stdc++.h>
using namespace std;
// recursive approach
int solve_1(int i, int j)
{
    // base case
    if (i == 0 && j == 0)
        return 1;

    int up = 0, left = 0;

    if (i > 0)
        up = solve_1(i - 1, j);

    if (j > 0)
        left = solve_1(i, j - 1);

    return up + left;
}
// meoization
int solve_2(int i, int j, vector<vector<int>> &dp)
{
    // base case
    if (i == 0 && j == 0)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = 0, left = 0;

    if (i > 0)
        up = solve_1(i - 1, j);

    if (j > 0)
        left = solve_1(i, j - 1);

    return dp[i][j] = up + left;
}
// tabulation
int solve_3(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            // base case
            if (i == 0 && j == 0)
            {
                dp[0][0]=1;
                continue;
            }
            int up = 0, left = 0;

            if (i > 0)
                up = dp[i - 1] [j];

            if (j > 0)
                left = dp[i] [j - 1];

            dp[i][j] = up + left;
        }
    }

    return dp[m - 1][n - 1];
}
// space optimization
int solve_4(int m, int n)
{
    vector<int> prev(n,0);

    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n,0);
        for (int j = 0; j < n; j++)
        {

            // base case
            if (i == 0 && j == 0)
            {
                curr[0]=1;
                continue;
            }
            int up = 0, left = 0;

            if (i > 0)
                up = prev [j];

            if (j > 0)
                left = curr [j - 1];

            curr[j] = up + left;
        }
        prev=curr;
    }

    return prev[n - 1];
}
int uniquePaths(int m, int n)
{
    // return solve_1(m-1,n-1);
    // vector<vector<int>> dp(m,vector<int> (n,-1));
    // return solve_2(m-1,n-1,dp);

    // return solve_3(m, n);
        return solve_4(m, n);
}

// https://leetcode.com/problems/unique-paths/submissions/1267416358/
int main()
{

    return 0;
}