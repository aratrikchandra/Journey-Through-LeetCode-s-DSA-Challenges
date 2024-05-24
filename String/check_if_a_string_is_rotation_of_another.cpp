#include <bits/stdc++.h>
using namespace std;
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
        return false;
        string temp=s+s;
        if(temp.find(goal)!=string::npos)
        return true;
        else
        return false;
    }
int main(){
  
  
  
return 0;
}
// https://leetcode.com/problems/rotate-string/submissions/1215114108/