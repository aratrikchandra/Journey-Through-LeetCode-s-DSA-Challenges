#include <bits/stdc++.h>
using namespace std;
// recursive approach
int solve_1(int ind, int buy, int cap, vector<int> &prices)
{
    // base case
    if (cap == 0)
        return 0;
    if (ind == prices.size())
        return 0;

    int val = 0;
    // allowed to buy
    if (buy == 0)
    {

        int Buy = -prices[ind] + solve_1(ind + 1, 1, cap, prices);
        int notBuy = 0 + solve_1(ind + 1, 0, cap, prices);
        val = max(Buy, notBuy);
    }
    else
    { // allowed to sell

        int sell = prices[ind] + solve_1(ind + 1, 0, cap - 1, prices);
        int notSell = 0 + solve_1(ind + 1, 1, cap, prices);
        val = max(sell, notSell);
    }
    return val;
}
// memoization
int solve_2(int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    // base case
    if (cap == 0)
        return 0;
    if (ind == prices.size())
        return 0;

    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];
    int val = 0;
    // allowed to buy
    if (buy == 0)
    {

        int Buy = -prices[ind] + solve_2(ind + 1, 1, cap, prices, dp);
        int notBuy = 0 + solve_2(ind + 1, 0, cap, prices, dp);
        val = max(Buy, notBuy);
    }
    else
    { // allowed to sell

        int sell = prices[ind] + solve_2(ind + 1, 0, cap - 1, prices, dp);
        int notSell = 0 + solve_2(ind + 1, 1, cap, prices, dp);
        val = max(sell, notSell);
    }
    return dp[ind][buy][cap] = val;
}
// tabulation
int solve_3(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    for (int i = 0; i <= n; i++)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            dp[i][buy][0] = 0;
        }
    }
    for (int buy = 0; buy <= 1; buy++)
    {
        for (int cap = 1; cap <= 2; cap++)
        {
            dp[n][buy][cap] = 0;
        }
    }

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                int val = 0;
                // allowed to buy
                if (buy == 0)
                {

                    int Buy = -prices[ind] + dp[ind+1][1][cap];
                    int notBuy = 0 + dp[ind+1][0][cap];
                    val = max(Buy, notBuy);
                }
                else
                { // allowed to sell

                    int sell = prices[ind] + dp[ind+1][0][cap-1];
                    int notSell = 0 + dp[ind+1][1][cap];
                    val = max(sell, notSell);
                }
                 dp[ind][buy][cap] = val;
            }
        }
    }
    return dp[0][0][2];
}
// space optimization
int solve_4(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> next(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                int val = 0;
                // allowed to buy
                if (buy == 0)
                {

                    int Buy = -prices[ind] + next[1][cap];
                    int notBuy = 0 + next[0][cap];
                    val = max(Buy, notBuy);
                }
                else
                { // allowed to sell

                    int sell = prices[ind] + next[0][cap-1];
                    int notSell = 0 + next[1][cap];
                    val = max(sell, notSell);
                }
                curr[buy][cap] = val;
            }
            next=curr;
        }
    }
    return next[0][2];
}

int maxProfit(vector<int> &prices)
{
    // return solve_1(0, 0, 2, prices);
    // int n = prices.size();
    // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    // return solve_2(0,0,2,prices,dp);
    return solve_3(prices);
}
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
int main()
{

    return 0;
}