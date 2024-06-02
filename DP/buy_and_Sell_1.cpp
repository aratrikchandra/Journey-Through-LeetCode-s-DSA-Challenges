#include <bits/stdc++.h>
using namespace std;
      int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxProfit=0;
        int minPrice=prices[0];

        for(int i=1;i<n;i++){
            int profit=prices[i]-minPrice;
            maxProfit=max(maxProfit,profit);
            minPrice=min(minPrice,prices[i]);
        }

        return maxProfit;
    }
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
int main(){
  
  
  
return 0;
}