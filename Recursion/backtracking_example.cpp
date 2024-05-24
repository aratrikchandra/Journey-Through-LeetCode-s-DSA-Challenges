#include <bits/stdc++.h>
using namespace std;
// print 1 to n using backtracking
void solve(vector<int> &arr,int n){
    if(n==0)
    return;

    solve(arr,n-1);
    arr.push_back(n);
}
vector<int> printNos(int x) {
    vector<int> ans;
    solve(ans,x);
    return ans;
}
// https://www.naukri.com/code360/problems/print-1-to-n_628290?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION

// print n to 1 using backtracking

void solve(vector<int> &arr,int i,int n){
    if(i>n)
    return;

    solve(arr,i+1,n);
    arr.push_back(i);
}
vector<int> printNos(int n) {
    vector<int> ans;
    solve(ans,1,n);
    return ans;
}
// https://www.naukri.com/code360/problems/n-to-1-without-loop_8357243?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION
int main(){
  
  
  
return 0;
}