#include <bits/stdc++.h>
using namespace std;
int solve_1(int ind, int tranNo, vector<int> &prices, int k)
{
    // base case
    if (tranNo == 2 * k)
        return 0;
    if (ind == prices.size())
        return 0;
    int val = 0;
    // buy is allowed
    if (tranNo % 2 == 0)
    {
        int Buy = -prices[ind] + solve_1(ind + 1, tranNo + 1, prices, k);
        int notBuy = 0 + solve_1(ind + 1, tranNo, prices, k);
        val = max(Buy, notBuy);
    }
    else
    { // sell is allowed
        int sell = prices[ind] + solve_1(ind + 1, tranNo + 1, prices, k);
        int notSell = 0 + solve_1(ind + 1, tranNo, prices, k);
        val = max(sell, notSell);
    }
    return val;
}
// memoization
int solve_2(int ind, int tranNo, vector<int> &prices, int k, vector<vector<int>> &dp)
{
    // base case
    if (tranNo == 2 * k)
        return 0;
    if (ind == prices.size())
        return 0;
    if (dp[ind][tranNo] != -1)
        return dp[ind][tranNo];

    int val = 0;
    // buy is allowed
    if (tranNo % 2 == 0)
    {
        int Buy = -prices[ind] + solve_2(ind + 1, tranNo + 1, prices, k, dp);
        int notBuy = 0 + solve_2(ind + 1, tranNo, prices, k, dp);
        val = max(Buy, notBuy);
    }
    else
    { // sell is allowed
        int sell = prices[ind] + solve_2(ind + 1, tranNo + 1, prices, k, dp);
        int notSell = 0 + solve_2(ind + 1, tranNo, prices, k, dp);
        val = max(sell, notSell);
    }
    return dp[ind][tranNo] = val;
}
// tabulation
int solve_3(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int tranNo = 2 * k - 1; tranNo >= 0; tranNo--)
        {
            int val = 0;
            // buy is allowed
            if (tranNo % 2 == 0)
            {
                int Buy = -prices[ind] + dp[ind + 1][tranNo + 1];
                int notBuy = 0 + dp[ind + 1][tranNo];
                val = max(Buy, notBuy);
            }
            else
            { // sell is allowed
                int sell = prices[ind] + dp[ind + 1][tranNo + 1];
                int notSell = 0 + dp[ind + 1][tranNo];
                val = max(sell, notSell);
            }
             dp[ind][tranNo] = val;
        }
    }
    return dp[0][0];
}
// space optimization
int solve_4(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<int> next(2 * k + 1, 0), curr(2*k+1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int tranNo = 2 * k - 1; tranNo >= 0; tranNo--)
        {
            int val = 0;
            // buy is allowed
            if (tranNo % 2 == 0)
            {
                int Buy = -prices[ind] +next[tranNo + 1];
                int notBuy = 0 + next[tranNo];
                val = max(Buy, notBuy);
            }
            else
            { // sell is allowed
                int sell = prices[ind] + next[tranNo + 1];
                int notSell = 0 + next[tranNo];
                val = max(sell, notSell);
            }
             curr[tranNo] = val;
        }
        next=curr;
    }
    return next[0];
}

int maxProfit(int k, vector<int> &prices)
{
    // return solve_1(0,0,prices,k);
    int n = prices.size();
    // vector<vector<int>> dp(n+1,vector<int> (2*k+1,-1));
    // return solve_2(0,0,prices,k,dp);
    return solve_3(k, prices);
}
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/1278777682/
int main()
{

    return 0;
}