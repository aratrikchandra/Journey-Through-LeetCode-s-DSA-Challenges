#include <bits/stdc++.h>
using namespace std;
int solve_1(int i, int j, vector<int> &arr)
{
    // base case
    if (i > j)
        return 0;
    int maxCoin = 0;
    // partition
    for (int k = i; k <= j; k++)
    {
        maxCoin = max(maxCoin, arr[i - 1] * arr[k] * arr[j + 1] + solve_1(i, k - 1, arr) + solve_1(k + 1, j, arr));
    }
    return maxCoin;
}
// meoization
int solve_2(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    // base case
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int maxCoin = 0;
    // partition
    for (int k = i; k <= j; k++)
    {
        maxCoin = max(maxCoin, arr[i - 1] * arr[k] * arr[j + 1] + solve_2(i, k - 1, arr, dp) + solve_2(k + 1, j, arr, dp));
    }
    return dp[i][j] = maxCoin;
}
// tabulation
int solve_3(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j++)
        {
            int maxCoin = 0;
            // partition
            for (int k = i; k <= j; k++)
            {
                maxCoin = max(maxCoin, arr[i - 1] * arr[k] * arr[j + 1] + dp[i][k-1] + dp[k+1][j]);
            }
             dp[i][j] = maxCoin;
        }
    }
    return dp[1][n];
}
int maxCoins(vector<int> &nums)
{
    int n = nums.size();

    nums.push_back(1);
    nums.insert(nums.begin(), 1);

    // return solve_1(1,n,nums);
    // vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    // return solve_2(1, n, nums, dp);

    return solve_3(nums,n);
}
// https://leetcode.com/problems/burst-balloons/submissions/1278608823/
int main()
{

    return 0;
}