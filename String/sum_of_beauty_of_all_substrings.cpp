#include <bits/stdc++.h>
using namespace std;
// approach 1
class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        int n=s.length();
        int freq[26]={0};
        for(int i=0;i<n;i++){
            memset(freq,0,sizeof freq);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int mini=INT_MAX;
                int maxi=0;
                for(int k=0;k<26;k++){
                    if(freq[k]>0){
                        mini=min(mini,freq[k]);
                        maxi=max(maxi,freq[k]);
                    }
                }
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};
// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/submissions/1217997463/

// approach 2
class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> map;
            multiset<int> st;
            for(int j=i;j<n;j++){
                if(st.find(map[s[j]])!=st.end()) // if freq entry for s[j] already exists
                st.erase(st.find(map[s[j]])); // erase just one occurence of the freq value not others

                map[s[j]]++;
                st.insert(map[s[j]]);

                ans=ans+(*st.rbegin()-*st.begin());
            }
        }
        return ans;
    }
};
// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/submissions/1286666923/

int main(){
  
  
  
return 0;
}