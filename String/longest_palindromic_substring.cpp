#include <bits/stdc++.h>
using namespace std;
    string longestPalindrome(string s) {
        // gap strategy
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool> (n,false));

        string ans;
        int len=0;
        int start=0;
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
                {
                  start=i;
                  len=g+1;  
                }
            }
        
        }
        ans=s.substr(start,len);
        return ans;
    }
// https://leetcode.com/problems/longest-palindromic-substring/submissions/1286657597/
int main(){
  
  
  
return 0;
}