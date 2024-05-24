#include <bits/stdc++.h>
using namespace std;

// one pointer instead of two pointer
bool solve(string &s,int left){
    // base case
    if(left>=(s.size()/2))
    return true;

    if(s[left]!=s[s.size()-left-1])
    return false; // we don't need to check further

    solve(s,left+1);
}
string adjust(string s){
    string ans="";
    for(int i=0;i<s.size();i++){
        if(isalnum(s[i]))
        ans+=s[i];
    }
    for (char& c : ans) {
        c = tolower(c);
    }
    return ans;
}
bool isPalindrome(string s) {
        s=adjust(s);
        return solve(s,0);
    }
int main(){
  
  
return 0;
}

// https://leetcode.com/problems/valid-palindrome/submissions/1219459469/