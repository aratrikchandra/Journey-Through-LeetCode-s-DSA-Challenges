#include <bits/stdc++.h>
using namespace std;
// better approach
int minAddToMakeValid(string s) {
        int n=s.size();
        stack<int> st;

        for(int i=0;i<n;i++){
            if(s[i]=='(')
            st.push(s[i]);

            else{
                if(!st.empty() && st.top()=='(')
                st.pop();
                else
                st.push(s[i]);
            }
        }
        return st.size();
    }

// optimal approach
int minAddToMakeValid(string s) {
        int n=s.size();
        int balance=0;
        int ans=0;

        for(int i=0;i<n;i++){
            if(s[i]=='(')
            balance++;
            else
            balance--;

            if(balance==-1)
            {
                ans+=1;
                balance=0;
            }
        }
        return ans+balance;
    }
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/submissions/1284158245/
int main(){
  
  
  
return 0;
}