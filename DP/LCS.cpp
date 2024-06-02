#include <bits/stdc++.h>
using namespace std;
// recusrsive approach
int solve_1(int i, int j, string s1, string s2)
{
    // base case
    if (i == 0 || j == 0)
        return 0;

    // try out all choices
    if (s1[i - 1] == s2[j - 1])
        return 1 + solve_1(i - 1, j - 1, s1, s2);
    else
        return max(solve_1(i - 1, j, s1, s2), solve_1(i, j - 1, s1, s2));
}
// memoization
int solve_2(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
    // base case
    if (i == 0 || j == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    // try out all choices
    if (s1[i - 1] == s2[j - 1])
        return dp[i][j] = 1 + solve_2(i - 1, j - 1, s1, s2, dp);
    else
        return dp[i][j] = max(solve_2(i - 1, j, s1, s2, dp), solve_2(i, j - 1, s1, s2, dp));
}
// tabulation
int solve_3(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // base case
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // try out all choices
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
// space optimization
int solve_4(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m + 1, 0);
    // base case
    for (int i = 0; i <= n; i++)
        prev[0] = 0;
    for (int j = 0; j <= m; j++)
        prev[j] = 0;

    for (int i = 1; i <= n; i++)
    {
        vector<int> curr(m + 1, 0);
        for (int j = 1; j <= m; j++)
        {
            // try out all choices
            if (s1[i - 1] == s2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
    }
    return prev[m];
}
int longestCommonSubsequence(string s1, string s2)
{
    // int n = s1.size();
    // int m = s2.size();
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // return solve_2(n, m, s1, s2, dp);

    return solve_3(s1, s2);
}
// https://leetcode.com/problems/longest-common-subsequence/submissions/1272685439/
int main()
{

    return 0;
}