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
int main(){
  
  
  
return 0;
}

// https://www.naukri.com/code360/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=SUBMISSION