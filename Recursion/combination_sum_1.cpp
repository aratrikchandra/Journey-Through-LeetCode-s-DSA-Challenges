#include <bits/stdc++.h>
using namespace std;
void solve(int ind,int target,vector<int> &ds,vector<vector<int>> &ans,vector<int> arr,int n){
    // base case
    if(ind==n)
    {
        if(target==0){ // valid answer
            ans.push_back(ds);
        }
        return;
    }
    // non pick case
    solve(ind+1,target,ds,ans,arr,n);   
    // pick case
    if(arr[ind]<=target){ // checking condition to pick
    ds.push_back(arr[ind]);
    solve(ind,target-arr[ind],ds,ans,arr,n);
    ds.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
     vector<vector<int>> ans;
    vector<int> ds;
    solve(0,target,ds,ans,arr,arr.size());
    return ans;   
}
// https://leetcode.com/problems/combination-sum/submissions/1222001824/
int main(){
  
  
  
return 0;
}