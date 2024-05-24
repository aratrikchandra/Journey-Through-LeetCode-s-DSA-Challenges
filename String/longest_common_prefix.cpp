#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string s1=strs[0]; // first word
        string s2=strs[strs.size()-1]; // last word

        int n=min(s1.length(),s2.length());
        string res="";
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i])
                break;
            else
                res=res+s1[i];
        }
        return res;
    }
int main(){
  
  vector<string> strs = {"flower","flow","flight"};
  cout<<longestCommonPrefix(strs);
    return 0;
}

// https://leetcode.com/problems/longest-common-prefix/submissions/1215155518/