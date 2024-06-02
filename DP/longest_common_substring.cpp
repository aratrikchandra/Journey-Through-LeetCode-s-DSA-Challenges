#include <bits/stdc++.h>
using namespace std;
int longestCommonSubstr(string s1, string s2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // base case
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // try out all choices
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return dp[n][m];
}
// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
int main()
{

    return 0;
}