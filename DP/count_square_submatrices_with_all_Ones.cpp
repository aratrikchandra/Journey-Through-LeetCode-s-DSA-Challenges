#include <bits/stdc++.h>
using namespace std;
int countSquares(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = matrix[i][0];
        ans += dp[i][0];
    }
    // avoid double counting of matrix[0][0]
    for (int j = 1; j < m; j++){
        dp[0][j] = matrix[0][j];
        ans+=dp[0][j];
    }
        

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {

            if (matrix[i][j] == 1)
            {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                ans += dp[i][j];
            }
            // else
            // dp[i][j]=0;
        }
    }
    return ans;
}
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/submissions/1279451456/
int main()
{

    return 0;
}