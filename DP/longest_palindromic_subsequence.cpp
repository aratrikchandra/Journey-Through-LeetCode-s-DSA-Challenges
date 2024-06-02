#include <bits/stdc++.h>
using namespace std;
// tabulation
int solve_3(string &s1, string &s2)
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
int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());

        return solve_3(s,t);
    }
// https://leetcode.com/problems/longest-palindromic-subsequence/submissions/1273553525/
int main(){
  
  
  
return 0;
}