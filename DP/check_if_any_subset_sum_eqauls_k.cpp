#include <bits/stdc++.h>
using namespace std;
// recursive approach
bool solve_1(int ind, int target, vector<int> &arr, int n)
{
    // base case
    if (target == 0)
        return true;

    if (ind == 0)
        return arr[0] == target;

    // try out all possibility
    bool notTake = solve_1(ind - 1, target, arr, n);

    bool take = false;
    // edge case
    if (arr[ind] <= target)
        take = solve_1(ind - 1, target - arr[ind], arr, n);

    return take | notTake;
}
// memoization
bool solve_2(int ind, int target, vector<int> &arr, int n, vector<vector<int>> &dp)
{
    // base case
    if (target == 0)
        return true;

    if (ind == 0)
        return arr[0] == target;
    if (dp[ind][target] != -1)
        return dp[ind][target];
    // try out all possibility
    bool notTake = solve_2(ind - 1, target, arr, n, dp);

    bool take = false;
    // edge case
    if (arr[ind] <= target)
        take = solve_2(ind - 1, target - arr[ind], arr, n, dp);

    return dp[ind][target] = take | notTake;
}
// tabulation
bool solve_3(vector<int> &arr, int k, int n)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    // base case
    for (int ind = 0; ind < n; ind++)
        dp[ind][0] = true;

    dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            // try out all possibility
            bool notTake = dp[ind - 1][target];

            bool take = false;
            // edge case
            if (arr[ind] <= target)
                take = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = take | notTake;
        }
    }
    return dp[n - 1][k];
}
// space optimization
bool solve_4(vector<int> &arr, int k, int n)
{
    vector<bool> prev(k + 1, false);
    // base case
    for (int ind = 0; ind < n; ind++)
        prev[0] = true;

    prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        vector<bool> curr(k + 1, false);
        curr[0]=true;
        for (int target = 1; target <= k; target++)
        {
            // try out all possibility
            bool notTake = prev[target];

            bool take = false;
            // edge case
            if (arr[ind] <= target)
                take = prev[target - arr[ind]];

            curr[target] = take | notTake;
        }
        prev=curr;
    }
    return prev[k];
}
bool isSubsetSum(vector<int> arr, int target)
{
    int n = arr.size();
    // return solve_1(n-1,target,arr,n);
    // vector<vector<int>> dp(n,vector<int>(target+1,-1));
    // return solve_2(n-1,target,arr,n,dp);
    return solve_3(arr, target, n);
}
// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
int main()
{

    return 0;
}