#include <bits/stdc++.h>
using namespace std;
int solve_1(int i, int k, int n, vector<int> &arr)
{
    // base case
    if (i == n)
        return 0;
    int maxSum = -1e9;
    int maxVal = -1e9;
    int len = 0;
    for (int j = i; j < min(n, i + k); j++)
    {
        len++;
        maxVal = max(maxVal, arr[j]);
        int sum = maxVal * len + solve_1(j + 1, k, n, arr);

        maxSum = max(sum, maxSum);
    }
    return maxSum;
}
// memoization
int solve_2(int i, int k, int n, vector<int> &arr, vector<int> &dp)
{
    // base case
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int maxSum = -1e9;
    int maxVal = -1e9;
    int len = 0;
    for (int j = i; j < min(n, i + k); j++)
    {
        len++;
        maxVal = max(maxVal, arr[j]);
        int sum = maxVal * len + solve_2(j + 1, k, n, arr, dp);

        maxSum = max(sum, maxSum);
    }
    return dp[i] = maxSum;
}
// tabulation
int solve_3(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, -1);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int maxSum = -1e9;
        int maxVal = -1e9;
        int len = 0;
        for (int j = i; j < min(n, i + k); j++)
        {
            len++;
            maxVal = max(maxVal, arr[j]);
            int sum = maxVal * len + dp[j+1];

            maxSum = max(sum, maxSum);
        }
         dp[i] = maxSum;
    }
    return dp[0];
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    // return solve_1(0,k,n,arr);
    // vector<int> dp(n + 1, -1);
    // return solve_2(0, k, n, arr, dp);
    return solve_3(arr,k);
}
// https://leetcode.com/problems/partition-array-for-maximum-sum/submissions/1279354396/
int main()
{

    return 0;
}