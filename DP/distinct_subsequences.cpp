#include <bits/stdc++.h>
using namespace std;
int mod=(1e9)+7;
// recusrsive approach
int solve_1(int i, int j, string &s1, string &s2)
{
    // base case
    if (j == 0)
        return 1;

    if (i == 0)
        return 0;

    if (s1[i - 1] == s2[j - 1])
    {
        int match = solve_1(i - 1, j - 1, s1, s2);
        int notMatch = solve_1(i - 1, j, s1, s2);

        return match + notMatch;
    }
    else
    {
        int notMatch = solve_1(i - 1, j, s1, s2);
        return notMatch;
    }
}
// memoization
int solve_2(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    // base case
    if (j == 0)
        return 1;

    if (i == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i - 1] == s2[j - 1])
    {
        int match = solve_2(i - 1, j - 1, s1, s2, dp);
        int notMatch = solve_2(i - 1, j, s1, s2, dp);

        return dp[i][j] = match + notMatch;
    }
    else
    {
        int notMatch = solve_2(i - 1, j, s1, s2, dp);
        return dp[i][j] = notMatch;
    }
}
// tabulation
int solve_3(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // base case
    for(int i=0;i<=n;i++)
    dp[i][0]=1;

    for(int j=1;j<=m;j++)
    dp[0][j]=0;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                int match = dp[i - 1][j - 1];
                int notMatch = dp[i - 1][j];

                dp[i][j] = (match + notMatch) %mod;
            }
            else
            {
                int notMatch = dp[i - 1][j];
                dp[i][j] = notMatch % mod;
            }
        }
    }
    return dp[n][m] %mod;
}
// space optimization
int solve_4(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int>prev (m + 1, -1), curr(m+1,-1);
    // base case
    prev[0]=1;

    for(int j=1;j<=m;j++)
    prev[j]=0;
    
    for (int i = 1; i <= n; i++)
    {
        curr[0]=1;
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                int match = prev[j - 1];
                int notMatch = prev[j];

                curr[j] = (match + notMatch) %mod;
            }
            else
            {
                int notMatch = prev[j];
                curr[j] = notMatch % mod;
            }
        }
        prev=curr;
    }
    return prev[m] %mod;
}
int numDistinct(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    // return solve_1(n,m,s1,s2);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve_2(n, m, s1, s2, dp);
}
// https://leetcode.com/problems/distinct-subsequences/submissions/1276067026/
int main()
{

    return 0;
}