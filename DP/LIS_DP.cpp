#include <bits/stdc++.h>
using namespace std;
// recursive approach
int solve_1(int ind, int prevIndex, vector<int> &nums, int n)
{
    // base case
    if (ind == n)
        return 0;

    int notTake = solve_1(ind + 1, prevIndex, nums, n);
    int take = -1e9;
    if (prevIndex == -1 || nums[ind] > nums[prevIndex])
        take = 1 + solve_1(ind + 1, ind, nums, n);

    return max(take, notTake);
}
// memoization
int solve_2(int ind, int prevIndex, vector<int> &nums, int n, vector<vector<int>> &dp)
{
    // base case
    if (ind == n)
        return 0;

    if (dp[ind][prevIndex + 1] != -1)
        return dp[ind][prevIndex + 1];

    int notTake = solve_2(ind + 1, prevIndex, nums, n, dp);
    int take = -1e9;
    if (prevIndex == -1 || nums[ind] > nums[prevIndex])
        take = 1 + solve_2(ind + 1, ind, nums, n, dp);

    return dp[ind][prevIndex + 1] = max(take, notTake);
}
// tabulation
int solve_3(vector<int> &nums)
{
    int n=nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // base case
    for (int j = 0; j <= n; j++)
        dp[n][j] = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prevIndex = ind - 1; prevIndex >=-1; prevIndex--)
        {

            int notTake = dp[ind + 1][prevIndex+1];
            int take = -1e9;
            if (prevIndex == -1 || nums[ind] > nums[prevIndex])
                take = 1 + dp[ind + 1][ind+1];

             dp[ind][prevIndex + 1] = max(take, notTake);
        }
    }
    return dp[0][-1+1];
}
//space optimization
int solve_4(vector<int> &nums)
{
    int n=nums.size();
    vector<int> next(n + 1, -1), curr(n+1,-1);
    // base case
    for (int j = 0; j <= n; j++)
        next[j] = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prevIndex = ind - 1; prevIndex >=-1; prevIndex--)
        {

            int notTake = next[prevIndex+1];
            int take = -1e9;
            if (prevIndex == -1 || nums[ind] > nums[prevIndex])
                take = 1 + next[ind+1];

             curr[prevIndex + 1] = max(take, notTake);
        }
        next=curr;
    }
    return next[-1+1];
}
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    // return solve_1(0,-1,nums,n);
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // return solve_2(0, -1, nums, n, dp);
    return solve_3(nums);
}
// https://leetcode.com/problems/longest-increasing-subsequence/submissions/1276695117/
int main()
{

    return 0;
}