#include <bits/stdc++.h>
using namespace std;

void solve(int ind,string &ds,vector<string> &ans,unordered_map<char,string> &umap,string digits,int n){
    // base case
    if(ind==n){
        ans.push_back(ds);
        return;
    }
    string s=umap[digits[ind]];
    for(int i=0;i<s.length();i++){
        ds+=s[i];
        solve(ind+1,ds,ans,umap,digits,n);
        ds.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string ds="";
        unordered_map<char,string> umap;
        umap['2']="abc";
        umap['3']="def";
        umap['4']="ghi";
        umap['5']="jkl";
        umap['6']="mno";
        umap['7']="pqrs";
        umap['8']="tuv";
        umap['9']="wxyz";
        if(digits.size()==0)
        return ans;
        solve(0,ds,ans,umap,digits,digits.size());
        return ans;
    }

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/1224236930/
int main(){
  
  string digits = "23";
  vector<string> ans=letterCombinations(digits);
  for(auto it:ans)
  cout<<it<<" ";
return 0;
}