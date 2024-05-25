#include <bits/stdc++.h>
using namespace std;

// recursive approach
int solve_1(int ind, vector<int> &nums)
{
    // base case
    if (ind == 0)
        return nums[ind];

    // non pick case
    int nonPick = 0 + solve_1(ind - 1, nums);
    // pick case
    int pick = nums[ind];
    if (ind >= 2)
        pick += solve_1(ind - 2, nums);

    return max(pick, nonPick);
}

// memoization

int solve_2(int ind, vector<int> &nums, vector<int> &dp)
{
    // base case
    if (ind == 0)
        return nums[ind];
    if (dp[ind] != -1)
        return dp[ind];
    // non pick case
    int nonPick = 0 + solve_2(ind - 1, nums, dp);
    // pick case
    int pick = nums[ind];
    if (ind >= 2)
        pick += solve_2(ind - 2, nums, dp);

    return dp[ind] = max(pick, nonPick);
}
// tabulation
int solve_3(int ind, vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);

    for (int ind = 0; ind < n; ind++)
    {
        // base case
        if (ind == 0)
        {
            dp[0] = nums[ind];
            continue;
        }
        // non pick case
        int nonPick = 0 + dp[ind - 1];
        // pick case
        int pick = nums[ind];
        if (ind >= 2)
            pick += dp[ind - 2];
        dp[ind] = max(pick, nonPick);
    }
    return dp[n-1];
}
// space optimization
int solve_4(int ind, vector<int> &nums)
{
    int n = nums.size();
    int prev,prev2;

    for (int ind = 0; ind < n; ind++)
    {
        int curr;
        // base case
        if (ind == 0)
        {
            prev = nums[ind];
            continue;
        }
        // non pick case
        int nonPick = 0 + prev;
        // pick case
        int pick = nums[ind];
        if (ind >= 2)
            pick += prev2;
        curr = max(pick, nonPick);

        prev2=prev;
        prev=curr;
    }
    return prev;
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    // return solve_1(n - 1, nums);
    // vector<int> dp(n,-1);
    // return solve_2(n-1,nums,dp);

    // return solve_3(n - 1, nums);
    return solve_4(n - 1, nums);
}
// https://leetcode.com/problems/house-robber/submissions/1267390677/
int main()
{

    return 0;
}