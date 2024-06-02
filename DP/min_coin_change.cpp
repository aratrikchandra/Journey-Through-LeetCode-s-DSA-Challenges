#include <bits/stdc++.h>
using namespace std;
   // recursive approach
int solve_1(int ind, int amount, vector<int>& coins){
    // base case
    if(ind==0){
        if(amount%coins[0]==0)
        return amount/coins[0];
        else
        return 1e9;
    }

    // try out all possible choices
    int notTake=solve_1(ind-1,amount,coins);
    int take=1e9;
    if(coins[ind]<=amount)
    take=1+solve_1(ind,amount-coins[ind],coins);

    return min(notTake,take);
}
// memoization
int solve_2(int ind, int amount, vector<int>& coins, vector<vector<int>> &dp){
    // base case
    if(ind==0){
        if(amount%coins[0]==0)
        return amount/coins[0];
        else
        return 1e9;
    }
    if(dp[ind][amount]!=-1) return dp[ind][amount];
    // try out all possible choices
    int notTake=solve_2(ind-1,amount,coins,dp);
    int take=1e9;
    if(coins[ind]<=amount)
    take=1+solve_2(ind,amount-coins[ind],coins,dp);

    return dp[ind][amount]= min(notTake,take);
}
// tabulation
int solve_3(int T, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(T + 1, -1));
    // base case
    for (int amount = 0; amount <= T; amount++)
    {
        if (amount % coins[0] == 0)
            dp[0][amount] = amount / coins[0];
        else
            dp[0][amount] = 1e9;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int amount = 0; amount <= T; amount++)
        {
            // try out all possible choices
            int notTake = dp[ind - 1][amount];
            int take = 1e9;
            if (coins[ind] <= amount)
                take = 1 + dp[ind][amount - coins[ind]];

            dp[ind][amount] = min(notTake, take);
        }
    }
    return dp[n-1][T];
}
// space optimization
int solve_4(int T, vector<int> &coins)
{
    int n = coins.size();
    vector<int> prev(T + 1, -1);
    // base case
    for (int amount = 0; amount <= T; amount++)
    {
        if (amount % coins[0] == 0)
            prev[amount] = amount / coins[0];
        else
            prev[amount] = 1e9;
    }
    for (int ind = 1; ind < n; ind++)
    {
        vector<int> curr(T + 1, -1);
        for (int amount = 0; amount <= T; amount++)
        {
            // try out all possible choices
            int notTake = prev[amount];
            int take = 1e9;
            if (coins[ind] <= amount)
                take = 1 + curr[amount - coins[ind]];

            curr[amount] = min(notTake, take);
        }
        prev=curr;
    }
    return prev[T];
}
int coinChange(vector<int> &coins, int T)
{
    // int n = coins.size();
    // vector<vector<int>> dp(n, vector<int>(T + 1, -1));
    // int ans = solve_2(n - 1, T, coins, dp);
    int ans=solve_4(T,coins);
    if (ans != 1e9)
        return ans;
    else
        return -1;
}
// https://leetcode.com/problems/coin-change/
int main()
{

    return 0;
}