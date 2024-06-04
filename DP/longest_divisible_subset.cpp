#include <bits/stdc++.h>
using namespace std;
   vector<int> largestDivisibleSubset(vector<int>& arr) {
    int n=arr.size();
    vector<int> ans;
    // edge case
    if(n==0)
    return ans;
    sort(arr.begin(),arr.end());
    vector<int> dp(n, 1);
    vector<int> parent(n);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev <= i - 1; prev++)
        {
            if (arr[i] % arr[prev]==0)
            {
                if (dp[prev] + 1 > dp[i])
                {
                    dp[i] = dp[prev] + 1;
                    parent[i] = prev;
                }
            }
        }
    }
    int maxLen = 0;
    int maxInd = -1;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > maxLen)
        {
            maxLen = max(maxLen, dp[i]);
            maxInd = i;
        }
    }

    int ind = maxInd;
    ans.push_back(arr[ind]);
    while (ind != parent[ind])
    {
        ind = parent[ind];
        ans.push_back(arr[ind]);
    }

    reverse(ans.begin(), ans.end());
    return ans;

    }
// https://leetcode.com/problems/largest-divisible-subset/
int main(){
  
  
  
return 0;
}