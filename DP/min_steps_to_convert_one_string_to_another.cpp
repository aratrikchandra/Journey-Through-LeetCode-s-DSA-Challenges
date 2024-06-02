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
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        return n+m-2*solve_3(word1,word2);
    }
// https://leetcode.com/problems/delete-operation-for-two-strings/submissions/1273561498/
int main(){
  
  
  
return 0;
}