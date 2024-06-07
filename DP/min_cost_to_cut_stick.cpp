#include <bits/stdc++.h>
using namespace std;
int solve_1(int i, int j, vector<int> &cuts)
{
    // base case
    if (i > j)
        return 0;
    int minCost = 1e9;
    // partition
    for (int k = i; k <= j; k++)
    {
        minCost = min(minCost, cuts[j + 1] - cuts[i - 1] + solve_1(i, k - 1, cuts) + solve_1(k + 1, j, cuts));
    }
    return minCost;
}
// memoization
int solve_2(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    // base case
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int minCost = 1e9;
    // partition
    for (int k = i; k <= j; k++)
    {
        minCost = min(minCost, cuts[j + 1] - cuts[i - 1] + solve_2(i, k - 1, cuts, dp) + solve_2(k + 1, j, cuts, dp));
    }
    return dp[i][j] = minCost;
}
// tabulation
int solve_3(vector<int> &cuts, int n, int c)
{
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--)
    {
        for (int j = i; j <= c; j++)
        {
            int minCost = 1e9;
            // partition
            for (int k = i; k <= j; k++)
            {
                minCost = min(minCost, cuts[j + 1] - cuts[i - 1] + dp[i][k-1] + dp[k + 1][j]);
            }
             dp[i][j] = minCost;
        }
    }
    return dp[1][c];
}
int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    sort(cuts.begin(), cuts.end());

    // return solve_1(1, c, cuts);
    // vector<vector<int>> dp(c+2,vector<int> (c+2,-1));
    // return solve_2(1,c,cuts,dp);

    return solve_3(cuts, n, c);
}
// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/submissions/1278559246/
int main()
{

    return 0;
}