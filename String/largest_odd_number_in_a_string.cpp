#include <bits/stdc++.h>
using namespace std;
string largestOddNumber(string num) {
    int n=num.length();
        for(int i=n-1;i>=0;i--){
            if(int(num[i])&1){
                // extract substring from index 0 to (i+1)-1
                return num.substr(0,i+1);
            }
        }
        return ""; // we didn't find any odd digit
}
int main(){
  
  cout<<largestOddNumber("123575864");
  
return 0;
}

// https://leetcode.com/problems/largest-odd-number-in-string/submissions/1215136379/