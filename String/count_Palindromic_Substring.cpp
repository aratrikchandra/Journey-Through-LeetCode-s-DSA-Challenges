#include <bits/stdc++.h>
using namespace std;
// tabulation
int countSubstrings(string s) {
        // gap strategy
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool> (n,false));

        int ans=0;
        for(int g=0;g<n;g++){
            for(int i=0, j=g;j<n;i++,j++){
                // base case
                if(g==0){
                    dp[i][j]=true;
                }
                else if(g==1){
                    dp[i][j]=(s[i]==s[j]);
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j]=true;
                    }
                    else
                        dp[i][j]=false;
                }

                if(dp[i][j]==true) // if the substring  s[i,...j] is palindrome
                ans++;
            }
        
        }
        return ans;
    }
// https://leetcode.com/problems/palindromic-substrings/submissions/1286636737/
int main(){
  
  
  
return 0;
}