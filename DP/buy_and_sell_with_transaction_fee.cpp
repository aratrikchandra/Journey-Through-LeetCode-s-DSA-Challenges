#include <bits/stdc++.h>
using namespace std;
    // space optimization(Buy and sell stock 2)
int solve_4(vector<int> &prices, int n, int fee)
{
    vector<int> next(2, -1);
    // base case
    next[0] = next[1] = 0;

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
                int Sell = prices[day] -fee + next[0]; // trans fee applied after complete transaction
                int notSell = 0 + next[1];
                value = max(Sell, notSell);
            }

             curr[buy] = value;
        }
        next=curr;
    }
    return next[0];
}
    int maxProfit(vector<int>& prices, int fee) {
        return solve_4(prices,prices.size(),fee);
    }
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
int main(){
  
  
  
return 0;
}