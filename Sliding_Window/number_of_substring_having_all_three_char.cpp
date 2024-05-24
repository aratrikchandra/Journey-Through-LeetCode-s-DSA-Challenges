#include <bits/stdc++.h>
using namespace std;
int numberOfSubstrings(string s) {
        int n=s.size();
        unordered_map<char,int> m;

        int left=0;
        int right=0;
        int count=0;

        for(right=0;right<n;right++){
            m[s[right]]++;

            while(m['a']>=1 && m['b']>=1 && m['c']>=1)
            {
                count+=n-right;
                m[s[left]]--;
                left++;
            }

        }
        return count;
    }
int main(){
  string s = "abcabc";
  cout<<numberOfSubstrings(s);
return 0;
}

// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/submissions/1203608806/