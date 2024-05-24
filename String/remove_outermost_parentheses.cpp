#include <bits/stdc++.h>
using namespace std;
// better approach
string removeOuterParentheses1(string s) {
        stack<char> st;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(!st.empty()) // current '(' is inner parentheses
                {
                    ans+=s[i];
                }
                st.push(s[i]);
            }
            else if(s[i]==')'){
                // we know s is always valid parentheses so we can pop right a way
                st.pop();
                if(!st.empty()){ // current ')' is inner parentheses
                {
                    ans+=s[i];
                }
                }
            }
        }
        return ans;
}
// optimal approach
string removeOuterParentheses(string s) {
    int open=0;
    int close=0;
    int start=0;
    string ans="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            open++;
        }
        else if(s[i]==')'){
            close++;
        }

        if(open==close) // we have reached the end of a group
        {
            ans=ans + s.substr(start+1,i-start-1);
            start=i+1; // starting index of new group
        }
    }
    return ans;
}

// https://leetcode.com/problems/remove-outermost-parentheses/submissions/1215296705/
int main(){
  string s = "(()())(())";
  cout<<removeOuterParentheses(s);
  
  
return 0;
}