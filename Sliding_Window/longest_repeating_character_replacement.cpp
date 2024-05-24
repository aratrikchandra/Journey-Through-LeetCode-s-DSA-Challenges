#include <bits/stdc++.h>
using namespace std;

// optimal 1
int findMaxFreq(unordered_map<char,int> &m){
    int maxVal=0;
    for(auto it: m){
        if(maxVal<it.second)
        maxVal=it.second;
    }
    return maxVal;
}
int characterReplacement1(string s, int k) {
        int n=s.size();
        int left=0;
        int right=0;
        int maxLen=0;
        unordered_map<char,int> m;
        for(right=0;right<n;right++){
            m[s[right]]++;
        
            while(left<=right && (right-left+1 - findMaxFreq(m))>k)
            {
                m[s[left]]--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
// optimal 2
int characterReplacement(string s, int k) {
        int n=s.size();
        int left=0;
        int right=0;
        int maxLen=0;
        unordered_map<char,int> m;
        int maxf=0;
        for(right=0;right<n;right++){
            m[s[right]]++;
            maxf=max(maxf,m[s[right]]);
            while(left<=right && (right-left+1 - maxf)>k)
            {
                m[s[left]]--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
int main(){
  string s="AABABBA";
  int k=1;
  cout<<characterReplacement(s,k);
return 0;
}
// https://leetcode.com/problems/longest-repeating-character-replacement/submissions/1203698473/

// https://leetcode.com/problems/longest-repeating-character-replacement/submissions/1203703225/