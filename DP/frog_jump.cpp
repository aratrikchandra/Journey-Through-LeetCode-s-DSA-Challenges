#include <bits/stdc++.h>
using namespace std;
// recursive approach
int solve_1(int ind, vector<int> &height)
{
    // base case
    if (ind == 0)
        return 0;

    // try out all possible option
    int oneStep = abs(height[ind] - height[ind - 1]) + solve_1(ind - 1, height);

    int twoStep = INT_MAX;
    if (ind >= 2) // edge case
        twoStep = abs(height[ind] - height[ind - 2]) + solve_1(ind - 2, height);

    return min(oneStep, twoStep);
}

// memoized approach
int solve_2(int ind, vector<int> &height, vector<int> &dp)
{
    // base case
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    // try out all possible option
    int oneStep = abs(height[ind] - height[ind - 1]) + solve_2(ind - 1, height, dp);

    int twoStep = INT_MAX;
    if (ind >= 2) // edge case
        twoStep = abs(height[ind] - height[ind - 2]) + solve_2(ind - 2, height, dp);

    return dp[ind] = min(oneStep, twoStep);
}
// tabulation
int solve_3(int n, vector<int> &height)
{
    vector<int> dp(n, -1);
    // base case
    dp[0] = 0;
    for (int ind = 1; ind < n; ind++)
    {
        // try out all possible option
        int oneStep = abs(height[ind] - height[ind - 1]) + dp[ind-1];

        int twoStep = INT_MAX;
        if (ind >= 2) // edge case
            twoStep = abs(height[ind] - height[ind - 2]) + dp[ind-2];

        dp[ind] = min(oneStep, twoStep);
    }
    return dp[n-1];
}
// space optimized
int solve_4(int n, vector<int> &height)
{
    // base case
    int prev=0;
    int prev2=0;
    int curr=0;
    for (int ind = 1; ind < n; ind++)
    {
        // try out all possible option
        int oneStep = abs(height[ind] - height[ind - 1]) + prev;

        int twoStep = INT_MAX;
        if (ind >= 2) // edge case
            twoStep = abs(height[ind] - height[ind - 2]) + prev2;

        curr = min(oneStep, twoStep);

        prev2=prev;
        prev=curr;
    }
    return prev;
}
int minimumEnergy(vector<int> &height, int n)
{
    // return solve_1(n-1,height);
    // vector<int> dp(n,-1);
    // return solve_2(n-1,height,dp);

    // return solve_3(n, height);
    return solve_4(n, height);
}
// https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump
int main()
{

    return 0;
}