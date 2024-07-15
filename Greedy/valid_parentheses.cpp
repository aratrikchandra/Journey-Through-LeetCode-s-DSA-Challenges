#include <bits/stdc++.h>
using namespace std;
bool checkValidString(string s) {
        int n=s.size();
        stack<int> open, star;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
            open.push(i);
            else if(s[i]=='*')
            star.push(i);
            else{
                if(!open.empty())
                open.pop();
                else if(!star.empty())
                star.pop();
                else
                    return false;
            }
        }

        while(!open.empty() && !star.empty()){
            int ind1=open.top();
            int ind2=star.top();
            if(ind1<ind2)
            {
                open.pop();
                star.pop();
            }
            else{
                return false;
            }
        }
        if(open.empty())
        return true;

        return false;
    }
int main(){
  
  string s = "(*))*(";
  cout<<checkValidString(s);
  
return 0;
}

// https://leetcode.com/problems/valid-parenthesis-string/submissions/1197454187/