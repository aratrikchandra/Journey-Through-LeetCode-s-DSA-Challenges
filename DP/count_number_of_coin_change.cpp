#include <bits/stdc++.h>
using namespace std;
   // recursive approach
int solve_1(int ind, int amount, vector<int>& coins){
    // base case
    if(ind==0){
        if(amount%coins[0]==0)
        return 1;
        else
        return 0;
    }

    // try out all possible choices
    int notTake=solve_1(ind-1,amount,coins);
    int take=0;
    if(coins[ind]<=amount)
    take=solve_1(ind,amount-coins[ind],coins);

    return notTake+take;
}
// memoization
int solve_2(int ind, int amount, vector<int>& coins, vector<vector<int>> &dp){
    // base case
    if(ind==0){
        if(amount%coins[0]==0)
        return 1;
        else
        return 0;
    }
    if(dp[ind][amount]!=-1) return dp[ind][amount];
    // try out all possible choices
    int notTake=solve_2(ind-1,amount,coins,dp);
    int take=0;
    if(coins[ind]<=amount)
    take=solve_2(ind,amount-coins[ind],coins,dp);

    return dp[ind][amount]= notTake+take;
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
            dp[0][amount] = 1;
        else
            dp[0][amount] = 0;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int amount = 0; amount <= T; amount++)
        {
            // try out all possible choices
            int notTake = dp[ind - 1][amount];
            int take = 0;
            if (coins[ind] <= amount)
                take = dp[ind][amount - coins[ind]];

            dp[ind][amount] = notTake + take;
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
            prev[amount] = 1;
        else
            prev[amount] = 0;
    }
    for (int ind = 1; ind < n; ind++)
    {
        vector<int> curr(T + 1, -1);
        for (int amount = 0; amount <= T; amount++)
        {
            // try out all possible choices
            int notTake = prev[amount];
            int take = 0;
            if (coins[ind] <= amount)
                take = curr[amount - coins[ind]];

            curr[amount] = notTake + take;
        }
        prev=curr;
    }
    return prev[T];
}

int change(int T, vector<int>& coins) {
            return solve_4(T,coins);
    }
// https://leetcode.com/problems/coin-change-ii/submissions/1272649185/
int main(){
  
  
  
return 0;
}