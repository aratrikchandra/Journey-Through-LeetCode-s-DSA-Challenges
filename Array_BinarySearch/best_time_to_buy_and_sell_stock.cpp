
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr)
{
    int n = arr.size();

    int minPrice = arr[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++)
    {
        maxProfit=max(maxProfit,arr[i]-minPrice);

        minPrice=min(minPrice,arr[i]);
    }
    return maxProfit;
}

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/1165137653/