#include <bits/stdc++.h>
using namespace std;
// recursive appraoch
int solve_1(int ind, int N, int price[])
{
    // base case
    if (ind == 0)
    {
        return N*price[0];
    }

    // try out pick/ non-pick
    int nonTake = 0 + solve_1(ind - 1, N, price);
    int take = 0;
    if (ind+1 <= N)
        take = price[ind] + solve_1(ind, N-(ind+1), price);

    return max(nonTake, take);
}
// memoization
int solve_2(int ind, int N, int price[], vector<vector<int>> &dp)
{
    // base case
    if (ind == 0)
    {
    return N*price[0];
    }
    if (dp[ind][N] != -1)
        return dp[ind][N];
    // try out pick/ non-pick
    int nonTake = 0 + solve_2(ind - 1, N, price, dp);
    int take = 0;
    if (ind+1 <= N)
        take = price[ind] + solve_2(ind, N - (ind+1), price, dp);

    return dp[ind][N] = max(nonTake, take);
}
// tabulation
int solve_3(int price[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    // base case
    for (int i = 0; i <= n; i++){
            dp[0][i]= i*price[0];
    }
        

    for (int ind = 1; ind < n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            // try out pick/ non-pick
            int nonTake = 0 + dp[ind - 1][N];
            int take = 0;
            if ((ind+1) <= N)
                take = price[ind] + dp[ind][N - (ind+1)];

            dp[ind][N] = max(nonTake, take);
        }
    }
    return dp[n - 1][n];
}
// space optimization 2 array
int solve_4(int price[], int n)
{
    vector<int> prev(n + 1, 0);
    // base case
    for (int i = 0; i <= n; i++)
        prev[i] = i*price[0];

    for (int ind = 1; ind < n; ind++)
    {
            vector<int> curr(n + 1, 0);
        for (int N = 0; N <= n; N++)
        {
            // try out pick/ non-pick
            int nonTake = 0 + prev[N];
            int take = 0;
            if ((ind+1) <= N)
                take = price[ind] + curr[N - (ind+1)];

            curr[N] = max(nonTake, take);
        }
        prev=curr;
    }
    return prev[n];
}
// space optimization 1 array
int solve_5(int price[], int n)
{
    vector<int> prev(n + 1, 0);
    // base case
    for (int i = 0; i <= n; i++)
        prev[i] = i*price[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int N = 0; N<=n; N++)
        {
            // try out pick/ non-pick
            int nonTake = 0 + prev[N];
            int take = 0;
            if ((ind+1) <= N)
                take = price[ind] + prev[N - (ind+1)];

            prev[N] = max(nonTake, take);
        }
    }
    return prev[n];
}
    int cutRod(int price[], int n) {
        // return solve_1(n-1,n,price);
        // vector<vector<int>> dp(n,vector<int> (n+1,-1));
        // return solve_2(n-1,n,price,dp);
    return solve_5(price, n);
    }

// https://www.geeksforgeeks.org/problems/rod-cutting0840/1
int main(){
  
  
  
return 0;
}