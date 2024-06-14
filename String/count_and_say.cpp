#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
        // base case
        if(n==1) return "1";
        if(n==2) return "11";

        string s="11";
        for(int i=3;i<=n;i++){
            string t="";
            int count=1;
            s+='#'; // adding a end of string delimeter such that we can take count of last char
            // to count freq of consective characters
            for(int j=1;j<s.size();j++){
                if(s[j-1]==s[j])
                count++;
                else{
                    t+=to_string(count); // storing the count
                    t+=s[j-1]; // storing the char

                    count=1;
                }
            }
            s=t;
        }
        return s;
    }
// https://leetcode.com/problems/count-and-say/submissions/1284135409/
int main(){
  
  
  
return 0;
}