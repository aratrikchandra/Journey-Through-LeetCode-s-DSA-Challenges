#include <bits/stdc++.h>
using namespace std;
void solve(int ind,int target,vector<int> &ds,vector<vector<int>> &ans,vector<int> &arr,int n){
    // base case
    if(target==0)
    {
        // put in final answer
        ans.push_back(ds);
        return;
    }

    for(int i=ind;i<n;i++){
        if(i!=ind && arr[i-1]==arr[i]) // skip duplicate element
        continue;
        if(arr[i]<=target) // condition to pick
        {
            ds.push_back(arr[i]);
            // recursive call
            solve(i+1,target-arr[i],ds,ans,arr,n);
            ds.pop_back();
        }
        else
            break; // if current element is greater than element then elements in right will be greater anyways
    }
}
vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        solve(0,target,ds,ans,arr,arr.size());
        return ans;
}
int main(){
  
  
  
return 0;
}
// https://leetcode.com/problems/combination-sum-ii/submissions/1223346196/