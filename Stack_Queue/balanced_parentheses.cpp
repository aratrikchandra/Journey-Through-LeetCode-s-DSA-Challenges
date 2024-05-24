#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else
            {
                if(st.empty())
                    return false;
                char val=st.top();
                st.pop();
                if(val=='(' && s[i]==')'   || val=='{' && s[i]=='}' || val=='[' && s[i]==']')
                {
                    continue;
                }
                else
                    return false;

            }
        }
        if(st.empty())
        return true;
        else
        return false;
    }
};
int main(){
  
  string s="()[{})]";
  Solution obj;
    if(obj.isValid(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
  
return 0;
}

// https://leetcode.com/problems/valid-parentheses/submissions/1192768697/