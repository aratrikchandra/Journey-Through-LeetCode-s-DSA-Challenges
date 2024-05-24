#include <bits/stdc++.h>
using namespace std;
void solve(int ind,string &ds,vector<string> &ans,string s,int n){
    // base case
    if(ind==n)
    {
        ans.push_back(ds);
        return;
    }
    // non pick case
    solve(ind+1,ds,ans,s,n);   
    // pick case
    ds=ds+s[ind];
    solve(ind+1,ds,ans,s,n);
    ds.pop_back();
}

vector<string> generateSubsequences(string s)
{
    vector<string> ans;
    string ds;
    solve(0,ds,ans,s,s.size());
    return ans;
}
int main(){
  
  
  
return 0;
}
// https://www.naukri.com/code360/problems/print-subsequences_8416366?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION