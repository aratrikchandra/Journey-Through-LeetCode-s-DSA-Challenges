#include <bits/stdc++.h>
using namespace std;

// recursive appraoch
int solve_1(int ind, int cap, int wt[], int val[], int n)
{
    // base case
    if (ind == 0)
    {
        return (cap/wt[0])*val[0];
    }

    // try out pick/ non-pick
    int nonTake = 0 + solve_1(ind - 1, cap, wt, val, n);
    int take = 0;
    if (wt[ind] <= cap)
        take = val[ind] + solve_1(ind, cap - wt[ind], wt, val, n);

    return max(nonTake, take);
}
// memoization
int solve_2(int ind, int cap, int wt[], int val[], int n, vector<vector<int>> &dp)
{
    // base case
    if (ind == 0)
    {
    return (cap/wt[0])*val[0];
    }
    if (dp[ind][cap] != -1)
        return dp[ind][cap];
    // try out pick/ non-pick
    int nonTake = 0 + solve_2(ind - 1, cap, wt, val, n, dp);
    int take = 0;
    if (wt[ind] <= cap)
        take = val[ind] + solve_2(ind, cap - wt[ind], wt, val, n, dp);

    return dp[ind][cap] = max(nonTake, take);
}
// tabulation
int solve_3(int wt[], int val[], int n, int W)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    // base case
    for (int i = 0; i <= W; i++){
            dp[0][i]= (i/wt[0])*val[0];
    }
        

    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = 0; cap <= W; cap++)
        {
            // try out pick/ non-pick
            int nonTake = 0 + dp[ind - 1][cap];
            int take = 0;
            if (wt[ind] <= cap)
                take = val[ind] + dp[ind][cap - wt[ind]];

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
    for (int i = 0; i <= W; i++)
        prev[i] = (i/wt[0])*val[0];

    for (int ind = 1; ind < n; ind++)
    {
            vector<int> curr(W + 1, 0);
        for (int cap = 0; cap <= W; cap++)
        {
            // try out pick/ non-pick
            int nonTake = 0 + prev[cap];
            int take = 0;
            if (wt[ind] <= cap)
                take = val[ind] + curr[cap - wt[ind]];

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
        prev[i] = (i/wt[0])*val[0];

    for (int ind = 1; ind < n; ind++)
    {
            // vector<int> curr(W + 1, 0);
        for (int cap = 0; cap<=W; cap++)
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
    int knapSack(int n, int W, int val[], int wt[])
    {
               //return solve_1(n-1,W,wt,val,n);
        // vector<vector<int>> dp(n,vector<int> (W+1,-1));
        // return solve_2(n-1,W,wt,val,n,dp);
    return solve_5(wt, val, n, W);
    }
// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=knapsack-with-duplicate-items
int main(){
  
  
  
return 0;
}