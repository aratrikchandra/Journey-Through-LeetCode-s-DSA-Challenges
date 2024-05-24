#include <bits/stdc++.h>
using namespace std;
void solve(int ind,int sum,int k,vector<int> &ds,vector<vector<int>> &ans,vector<int> arr,int n){
    // base case
    if(ind==n)
    {
        if(sum==k){ // valid answer
            ans.push_back(ds);
        }
        return;
    }
    // non pick case
    solve(ind+1,sum,k,ds,ans,arr,n);   
    // pick case
    ds.push_back(arr[ind]);
    sum+=arr[ind];
    solve(ind+1,sum,k,ds,ans,arr,n);
    sum-=arr[ind];
    ds.pop_back();
}

vector<vector<int>> generateSubsequencesWithSumK(vector<int> s,int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int sum=0;
    solve(0,sum,k,ds,ans,s,s.size());
    return ans;
}
int main(){
  vector<int> arr={1, 2, 3,4};
  int k=5;
  vector<vector<int>> ans=generateSubsequencesWithSumK(arr,k);
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
  
return 0;
}