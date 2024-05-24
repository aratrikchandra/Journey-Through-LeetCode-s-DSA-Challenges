#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int left,int right){
    while(left<=right){
        if(s[left]!=s[right])
        return false;

        left++;
        right--;
    }
    return true;
}
void solve(int ind,vector<string> &ds,vector<vector<string>> &ans,string s,int n){
    // base case
    if(ind==n)
    {
        ans.push_back(ds);
        return;
    }
    // try to make partition
    for(int i=ind;i<n;i++){
        if(isPalindrome(s,ind,i)){ // we can make partition at index 'i'
            ds.push_back(s.substr(ind,i-ind+1));
            solve(i+1,ds,ans,s,n);
            ds.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
      vector<vector<string>> ans;
      vector<string> ds;
      solve(0,ds,ans,s,s.size());
      return ans;  
}

// https://leetcode.com/problems/palindrome-partitioning/submissions/1223935041/
int main(){
  
  
  
return 0;
}