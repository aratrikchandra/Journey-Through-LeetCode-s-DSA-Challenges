#include <bits/stdc++.h>
using namespace std;
bool checkValidString(string s) {
        stack<int> open,star;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            open.push(i);
            else if(s[i]=='*')
            star.push(i);
            else{
                // we encounter ')'
                if(!open.empty())
                open.pop();
                else{
                    if(!star.empty())
                    star.pop();
                    else
                    return false;
                }
            }
        }

        while(!open.empty())
        {
            int i=open.top();
            open.pop();
            if(!star.empty())
            {
            int j=star.top();
            star.pop();
            if(i>j)
            return false;
            }
            else{
                return false;
            }
        }
        return true;
    }
int main(){
  
  string s = "(*))*(";
  cout<<checkValidString(s);
  
return 0;
}

// https://leetcode.com/problems/valid-parenthesis-string/submissions/1197454187/