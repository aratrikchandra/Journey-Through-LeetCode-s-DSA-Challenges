#include <bits/stdc++.h>
using namespace std;
// recursive approach
int solve_1(int day, int buy, vector<int> &prices, int n)
{
    // base case
    if (day >= n)
        return 0;

    // try out all possibillity
    if (buy == 0) // allowed to buy but not allowed to sell
    {
        int Buy = -prices[day] + solve_1(day + 1, 1, prices, n);
        int notBuy = 0 + solve_1(day + 1, 0, prices, n);

        return max(Buy, notBuy);
    }
    else
    { // not allowed to buy but allowed to sell
        int Sell = prices[day] + solve_1(day + 2, 0, prices, n);
        int notSell = 0 + solve_1(day + 1, 1, prices, n);
        return max(Sell, notSell);
    }
}
// memoization
int solve_2(int day, int buy, vector<int> &prices, int n, vector<vector<int>> &dp)
{
    // base case
    if (day >= n)
        return 0;

    if (dp[day][buy] != -1)
        return dp[day][buy];
    int value = 0;
    // try out all possibillity
    if (buy == 0) // allowed to buy but not allowed to sell
    {
        int Buy = -prices[day] + solve_2(day + 1, 1, prices, n, dp);
        int notBuy = 0 + solve_2(day + 1, 0, prices, n, dp);

        value = max(Buy, notBuy);
    }
    else
    { // not allowed to buy but allowed to sell
        int Sell = prices[day] + solve_2(day + 2, 0, prices, n, dp);
        int notSell = 0 + solve_2(day + 1, 1, prices, n, dp);
        value = max(Sell, notSell);
    }

    return dp[day][buy] = value;
}
// tabulation
int solve_3(vector<int> &prices, int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(2, -1));
    // base case
    dp[n+1][0]=dp[n+1][1]=dp[n][0] = dp[n][1] = 0;

    for (int day = n - 1; day >= 0; day--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int value = 0;
            // try out all possibillity
            if (buy == 0) // allowed to buy but not allowed to sell
            {
                int Buy = -prices[day] + dp[day+1][1];
                int notBuy = 0 + dp[day+1][0];

                value = max(Buy, notBuy);
            }
            else
            { // not allowed to buy but allowed to sell
                int Sell = prices[day] + dp[day+2][0];
                int notSell = 0 + dp[day+1][1];
                value = max(Sell, notSell);
            }

             dp[day][buy] = value;
        }
    }
    return dp[0][0];
}
// space optimization
int solve_4(vector<int> &prices, int n)
{
    vector<int> next(2, -1), next2(2,-1);
    // base case
    next2[0]=next2[1]=next[0] = next[1] = 0;

    for (int day = n - 1; day >= 0; day--)
    {
            vector<int> curr(2, -1);
        for (int buy = 0; buy <= 1; buy++)
        {
            int value = 0;
            // try out all possibillity
            if (buy == 0) // allowed to buy but not allowed to sell
            {
                int Buy = -prices[day] + next[1];
                int notBuy = 0 + next[0];

                value = max(Buy, notBuy);
            }
            else
            { // not allowed to buy but allowed to sell
                int Sell = prices[day] + next2[0];
                int notSell = 0 + next[1];
                value = max(Sell, notSell);
            }

             curr[buy] = value;
        }
        next2=next;
        next=curr;
    }
    return next[0];
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // return solve_1(0,0,prices,n);
    // vector<vector<int>> dp(n, vector<int>(2, -1));
    // return solve_2(0, 0, prices, n, dp);
    return solve_3(prices,n);
}
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/1275172522/
int main(){
  
  
  
return 0;
}