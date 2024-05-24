#include <bits/stdc++.h>
using namespace std;

// recursive approach
int solve_1(int ind, vector<int> &height, int k)
{
    // base case
    if (ind == 0)
        return 0;

    // try out all possible option
    int min_jump = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        // check the validity of the jump
        if (ind - j >= 0)
        { // edge case
            int jump;
            jump = abs(height[ind] - height[ind - j]) + solve_1(ind - j, height, k);

            min_jump = min(min_jump, jump);
        }
    }
    return min_jump;
}

// memoized approach
int solve_2(int ind, vector<int> &height, vector<int> &dp,int k)
{
    // base case
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
       // try out all possible option
    int min_jump = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        // check the validity of the jump
        if (ind - j >= 0)
        { // edge case
            int jump;
            jump = abs(height[ind] - height[ind - j]) + solve_2(ind - j, height,dp, k);

            min_jump = min(min_jump, jump);
        }
    }
    return dp[ind]=min_jump;
}
// tabulation
int solve_3(int n, vector<int> &height,int k)
{
    vector<int> dp(n, -1);
    // base case
    dp[0] = 0;
    for (int ind = 1; ind < n; ind++)
    {
    int min_jump = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        // check the validity of the jump
        if (ind - j >= 0)
        { // edge case
            int jump;
            jump = abs(height[ind] - height[ind - j]) + dp[ind - j];

            min_jump = min(min_jump, jump);
        }
    }
     dp[ind]=min_jump;
    }
    return dp[n - 1];
}

int minimizeCost(vector<int> &height, int n, int k)
{
    // return solve_1(n-1,height,k);
    // vector<int> dp(n,-1);
    // return solve_2(n-1,height,dp,k);

    // return solve_3(n, height,k);
}
// https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost
int main()
{

    return 0;
}