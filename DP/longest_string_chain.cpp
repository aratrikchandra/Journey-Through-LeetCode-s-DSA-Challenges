#include <bits/stdc++.h>
using namespace std;
bool check(string &s1, string &s2){
    int n=s1.size();
    int m=s2.size();

    // edge case
    if(n!=m+1)
    return false;
    int i=0,j=0;
    while(i<n){
        if(s1[i]==s2[j])
        {
            i++; j++;
        }
        else{
            i++;
        }
    }
    if(i==n && j==m)
    return true;

    return false;
}
int comp(string &s1, string &s2){
    return s1.size()<s2.size();
}
int longestStrChain(vector<string>& words) {
    int n = words.size();
    sort(words.begin(), words.end(),comp);
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        for(int prev=0;prev<=i-1;prev++)
        {
            if(check(words[i],words[prev])){
                if(dp[prev]+1 > dp[i])
                {
                    dp[i]=dp[prev]+1;
                }
            }
        }
    }
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > maxLen)
        {
            maxLen = dp[i];
        }
    }

    return maxLen;
    
}
// https://leetcode.com/problems/longest-string-chain/submissions/1277741911/
int main(){
  
  
  
return 0;
}