#include <bits/stdc++.h>
using namespace std;

// issue with the condition: if (dp[i-1][j]>=dp[i][j-1])

// when s1[i-1] is not equal to s2[j-1], you’re checking if dp[i-1][j] is greater than or equal to dp[i][j-1]. If it is, you’re adding s1[i-1] to the answer and decrementing i. Otherwise, you’re adding s2[j-1] to the answer and decrementing j.

// The issue here is that this condition doesn’t necessarily choose the character that would lead to the shortest common supersequence. It’s choosing the character based on which of dp[i-1][j] or dp[i][j-1] is larger, but this doesn’t guarantee that choosing this character will lead to the shortest common supersequence.

// In the corrected code, when s1[i-1] is not equal to s2[j-1], we’re still checking if dp[i-1][j] is greater than dp[i][j-1]. However, now if dp[i-1][j] is greater, we’re adding s1[i-1] to the answer and decrementing i. If dp[i][j-1] is greater, we’re adding s2[j-1] to the answer and decrementing j. If they’re equal, we can add either character.

// This change ensures that we’re always choosing the character that leads to the shortest common supersequence. The key difference is that we’re making the decision based on which choice will lead to a shorter supersequence, rather than simply which choice has a larger value in the dp table.

// LCS code
int lcs(string s1, string s2, vector<vector<int>> &dp)
{
    int n = s1.size();
    int m = s2.size();
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
string shortestCommonSupersequence(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    lcs(s1, s2, dp);

    string ans = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            ans += s1[i - 1];
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += s1[i - 1];
                i--;
            } else {
                ans += s2[j - 1];
                j--;
            }
        }
    }

    while (i > 0) {
        ans += s1[i - 1];
        i--;
    }

    while (j > 0) {
        ans += s2[j - 1];
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
// https://leetcode.com/problems/shortest-common-supersequence/
int main() {

  string s1 = "bbbaaaba";
  string s2 = "bbababbb";

  // expected o/p: "bbbaaababbb"
  // my o/p : "bbababbbaaaba"

  cout << "The Longest Common Supersequence is "<<shortestCommonSupersequence(s1,s2);
}