#include <bits/stdc++.h>
using namespace std;

// recursive appraoch
int solve_1(int ind, int cap, int wt[], int val[], int n)
{
    // base case
    if (ind == 0)
    {
        if (wt[0] <= cap)
            return val[0];

        return 0;
    }

    // try out pick/ non-pick
    int nonTake = 0 + solve_1(ind - 1, cap, wt, val, n);
    int take = 0;
    if (wt[ind] <= cap)
        take = val[ind] + solve_1(ind - 1, cap - wt[ind], wt, val, n);

    return max(nonTake, take);
}
// memoization
int solve_2(int ind, int cap, int wt[], int val[], int n, vector<vector<int>> &dp)
{
    // base case
    if (ind == 0)
    {
        if (wt[0] <= cap)
            return val[0];

        return 0;
    }
    if (dp[ind][cap] != -1)
        return dp[ind][cap];
    // try out pick/ non-pick
    int nonTake = 0 + solve_2(ind - 1, cap, wt, val, n, dp);
    int take = 0;
    if (wt[ind] <= cap)
        take = val[ind] + solve_2(ind - 1, cap - wt[ind], wt, val, n, dp);

    return dp[ind][cap] = max(nonTake, take);
}
// tabulation
int solve_3(int wt[], int val[], int n, int W)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    // base case
    for (int i = wt[0]; i <= W; i++)
        dp[0][i] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = 0; cap <= W; cap++)
        {
            // try out pick/ non-pick
            int nonTake = 0 + dp[ind - 1][cap];
            int take = 0;
            if (wt[ind] <= cap)
                take = val[ind] + dp[ind - 1][cap - wt[ind]];

            dp[ind][cap] = max(nonTake, take);
        }
    }
    return dp[n - 1][W];
}
// space optimization 2 array
int solve_4(int wt[], int val[], int n, int W)
{
    vector<int> prev(W + 1, 0);
    // base case
    for (int i = wt[0]; i <= W; i++)
        prev[i] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
            vector<int> curr(W + 1, 0);
        for (int cap = 0; cap <= W; cap++)
        {
            // try out pick/ non-pick
            int nonTake = 0 + prev[cap];
            int take = 0;
            if (wt[ind] <= cap)
                take = val[ind] + prev[cap - wt[ind]];

            curr[cap] = max(nonTake, take);
        }
        prev=curr;
    }
    return prev[W];
}
// space optimization 1 array
int solve_5(int wt[], int val[], int n, int W)
{
    vector<int> prev(W + 1, 0);
    // base case
    for (int i = wt[0]; i <= W; i++)
        prev[i] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
            // vector<int> curr(W + 1, 0);
        for (int cap = W; cap >= 0; cap--)
        {
            // try out pick/ non-pick
            int nonTake = 0 + prev[cap];
            int take = 0;
            if (wt[ind] <= cap)
                take = val[ind] + prev[cap - wt[ind]];

            prev[cap] = max(nonTake, take);
        }
        // prev=curr;
    }
    return prev[W];
}
int knapSack(int W, int wt[], int val[], int n)
{
    //    return solve_1(n-1,W,wt,val,n);
    //     vector<vector<int>> dp(n,vector<int> (W+1,-1));
    //    return solve_2(n-1,W,wt,val,n,dp);
    return solve_3(wt, val, n, W);
}
// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
int main()
{

    return 0;
}