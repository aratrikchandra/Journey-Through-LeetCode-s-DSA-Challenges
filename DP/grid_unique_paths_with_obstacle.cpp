#include <bits/stdc++.h>
using namespace std;
// tabulation
int solve_3(int m, int n, vector<vector<int>>& obstacleGrid)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            // base case 1 (dead cell)
            if(obstacleGrid[i][j]==-1)
            {
                dp[i][j]=0;
                continue;
            }
            // base case 2 (starting cell)
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
int solve_4(int m, int n, vector<vector<int>>& obstacleGrid)
{
    vector<int> prev(n,0);

    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n,0);
        for (int j = 0; j < n; j++)
        {
            // base case 1 (dead cell)
            if(obstacleGrid[i][j]==-1)
            {
                curr[j]=0;
                continue;
            }
            // base case 2 (starting cell)
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


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
    return solve_3(m, n,obstacleGrid);
    // return solve_4(m, n,obstacleGrid);
    }

// https://leetcode.com/problems/unique-paths-ii/submissions/1267421651/
int main(){
  
  
  
return 0;
}