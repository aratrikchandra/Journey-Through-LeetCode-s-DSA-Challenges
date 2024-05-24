#include <bits/stdc++.h>
using namespace std;
int romanToInt(string s) {
        map<char,int> mp;
        // mapping table
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(i+1<s.length() && mp[s[i]]<mp[s[i+1]]){
                ans-=mp[s[i]];
            }
            else{
               ans+=mp[s[i]]; 
            }
        }
        return ans;
    }
int main(){

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
  
  string s = "LVIII";
  cout<<romanToInt(s);
  
return 0;
}

// https://leetcode.com/problems/roman-to-integer/submissions/1216662082/