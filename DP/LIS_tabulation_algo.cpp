#include <bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size();

    vector<int> dp(n,1);
    int maxLen=1;
    for(int i=0;i<n;i++){
        for(int prev=0;prev<=i-1;prev++)
        {
            if(arr[prev]<arr[i]){
                if(dp[prev]+1 > dp[i])
                {
                    dp[i]=dp[prev]+1;
                    maxLen=max(maxLen,dp[i]);
                }
            }
        }
    }
    return maxLen;
    
}
// https://leetcode.com/problems/longest-increasing-subsequence/submissions/1277421568/
int main(){
  
  
  
return 0;
}