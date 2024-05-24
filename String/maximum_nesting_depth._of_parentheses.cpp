#include <bits/stdc++.h>
using namespace std;
 int maxDepth(string s) {
    int open=0;
    int maxVal=0;

    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            open++;
        }
        else if(s[i]==')'){
            if(open>0)
            open--;
            else   // s is surely not VPS
            return -1;
        }
        maxVal=max(maxVal,open);
    }
    if(open==0)
    return maxVal;
    else
    return -1; // s is surely not VPS
}
int main(){
  
  string s = "(1+(2*3)+((8)/4))+1";
  cout<<maxDepth(s);
  
return 0;
}

// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/submissions/1215304323/