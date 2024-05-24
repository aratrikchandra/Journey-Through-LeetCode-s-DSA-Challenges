#include <bits/stdc++.h>
using namespace std;
void solve(int open,int close,string &ds,vector<string> &ans,int n){
    // base case
    if(open==n && close==n){
        ans.push_back(ds);
        return;
    }
    // add open parentheses
    if(open<n){
    ds+='(';
    solve(open+1,close,ds,ans,n);
    ds.pop_back();
    }
    // add closing parentheses
    if(close<open){ // required for valid parentheses checking
    ds+=')';
    solve(open,close+1,ds,ans,n);
    ds.pop_back(); 
    }
}
vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds="";
        int open=0;
        int close=0;
        solve(open,close,ds,ans,n);
        return ans;
}
int main(){
  
  
  
return 0;
}

// https://leetcode.com/problems/generate-parentheses/submissions/1224247614/