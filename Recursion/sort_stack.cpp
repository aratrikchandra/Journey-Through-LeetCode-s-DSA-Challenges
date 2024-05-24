#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &s,int x){
    // base case 1
    if(s.empty()){
    s.push(x);
    return;
   }
    // base case 2
   if(x>=s.top())
   {
    s.push(x);
    return;
   }
    int item=s.top();
    s.pop();
    sortedInsert(s,x);
    s.push(item);
}
void sortStack(stack<int> &s)
{
	if(s.empty()){
    return;
   }
    int item=s.top();
    s.pop();
    sortStack(s); // returns the remaining stack in sorted manner
    sortedInsert(s,item); // insert the current item in sorted manner
}
int main(){
  
  
  
return 0;
}
// https://www.naukri.com/code360/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=SUBMISSION