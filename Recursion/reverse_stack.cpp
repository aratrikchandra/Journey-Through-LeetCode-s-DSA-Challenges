#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s,int x){
    // base case
     if (s.empty()) {
      s.push(x);
      return;
    }

    int item=s.top();
    s.pop();
    solve(s,x);
    s.push(item);
}
stack<int> pushAtBottom(stack<int>& s, int x) 
{
    solve(s,x);
    return s;
}
void reverseStack(stack<int> &s) {
    // base case
   if(s.empty()){
    return;
   }
    int item=s.top();
    s.pop();
    reverseStack(s);  // returns the remaining stack in reversed manner
    pushAtBottom(s,item); // insert the current item at the bottom of the stack
}
int main(){
  
  
  
return 0;
}

// https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION