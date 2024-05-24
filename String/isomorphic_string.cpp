#include <bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s, string t) {
        // first check
        if(s.size()!=t.size())
        return false;

        unordered_map<char,char> mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){ // the current char is already present in the map as key
                if(mp[s[i]]!=t[i])
                return false;  // the current mapping s[i]->t[i] should match with the existing maooing in the map
            }
            else{ // the current char not present in the map as key
            // now we have to  check if the t[i] character already exist as "value" in some entry of the map
            for(auto it:mp){
                if(it.second==t[i])
                return false;
            }
            // we are here means t[i] is not in value field previously
            mp[s[i]]=t[i];
            }
        }
        return true;
    }
int main(){
  
  string s = "paper", t = "tifle";
  cout<<isIsomorphic(s,t);
  
return 0;
}

// https://leetcode.com/problems/isomorphic-strings/submissions/1215284448/