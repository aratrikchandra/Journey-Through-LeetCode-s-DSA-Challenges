#include <bits/stdc++.h>
using namespace std;
// recursive approach
int solve_1(int i, int j, string &s1, string &s2) // always pass strings by reference
{
    // base case
    if (i == 0)
        return j;
    if (j == 0)
        return i;

    if (s1[i - 1] == s2[j - 1])
        return 0 + solve_1(i - 1, j - 1, s1, s2);
    else
    {
        int insertOp = solve_1(i, j - 1, s1, s2);
        int deleteOp = solve_1(i - 1, j, s1, s2);
        int replaceOp = solve_1(i - 1, j - 1, s1, s2);
        return 1 + min(insertOp, min(deleteOp, replaceOp));
    }
}
// memoization
int solve_2(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) // always pass strings by reference
{
    // base case
    if (i == 0)
        return j;
    if (j == 0)
        return i;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i - 1] == s2[j - 1])
        return dp[i][j] = 0 + solve_2(i - 1, j - 1, s1, s2,dp);
    else
    {
        int insertOp = solve_2(i, j - 1, s1, s2, dp);
        int deleteOp = solve_2(i - 1, j, s1, s2, dp);
        int replaceOp = solve_2(i - 1, j - 1, s1, s2, dp);
        return dp[i][j] = 1 + min(insertOp, min(deleteOp, replaceOp));
    }
}
// tabulation
int solve_3(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
               dp[i][j] = dp[i-1][j-1];
            else
            {
                int insertOp = dp[i][j-1];
                int deleteOp = dp[i-1][j];
                int replaceOp = dp[i-1][j-1];
                 dp[i][j] = 1 + min(insertOp, min(deleteOp, replaceOp));
            }
        }
    }
    return dp[n][m];
}
// space optimization
int solve_4(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int>prev(m + 1, -1), curr(m+1,-1);

    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        curr[0]=i;
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
               curr[j] = prev[j-1];
            else
            {
                int insertOp = curr[j-1];
                int deleteOp = prev[j];
                int replaceOp = prev[j-1];
                curr[j] = 1 + min(insertOp, min(deleteOp, replaceOp));
            }
        }
        prev=curr;
    }
    return prev[m];
}
int minDistance(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    // return solve_1(n,m,s1,s2);
    // vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
    // return solve_2(n,m,s1,s2,dp);
    return solve_3(s1, s2);
}
// https://leetcode.com/problems/edit-distance/submissions/1275527872/
int main()
{

    return 0;
}