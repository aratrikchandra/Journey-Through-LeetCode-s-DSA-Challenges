#include <bits/stdc++.h>
using namespace std;


// The issue with map is it inherently sorts the elements by their keys. In this case, since the keys are strings, they're sorted alphabetically, not by the integer values you're associating with the Roman numerals. Therefore, when you iterate over the map in reverse, the iteration order won't match the descending order of Roman numeral values. A better approach would be to use a vector of pairs, ensuring the correct order of Roman numeral symbols.
string intToRoman(int num) {
        // map<string,int> mp;
        // // mapping table
        // mp["I"]=1;
        // mp["IV"]=4;// extra
        // mp["V"]=5;
        // mp["IX"]=9;// extra
        // mp["X"]=10;
        // mp["XL"]=40; // extra
        // mp["L"]=50;
        // mp["XC"]=90; // extra
        // mp["C"]=100;
        // mp["CD"]=400; // extra
        // mp["D"]=500;
        // mp["CM"]=900;  // extra
        // mp["M"]=1000;

      vector<pair<int, string>> values = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
        string ans="";
        for(auto it: values){
          if(num >=(it.first)){
              int count=num/(it.first);
              for(int i=0;i<count;i++){
                ans=ans+(it.second);
              }
              num=num%(it.first);
          }
        }
  return ans;
}

// https://leetcode.com/problems/integer-to-roman/submissions/1217953345/
int main(){
  int num= 105;
  cout<<intToRoman(num);
  
return 0;
}