#include <bits/stdc++.h>
using namespace std;
// Striver sde sheet
// Approach 1
void solve1(vector<int> &ds,vector<vector<int>> &ans,vector<int> &visited,vector<int> &arr,int n){
    // base case
    if(ds.size()==n){
        ans.push_back(ds);
        return;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            // not included till now
            ds.push_back(arr[i]);
            visited[i]=1;
            solve1(ds,ans,visited,arr,n);
            visited[i]=0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permute1(vector<int>& arr) {
        vector<int> ds;
        vector<vector<int>> ans;
        vector<int> visited(arr.size(),0);
        solve1(ds,ans,visited,arr,arr.size());
        return ans;
    }
// https://leetcode.com/problems/permutations/submissions/1224019284/

// Approach 2
void solve(int ind,vector<vector<int>> &ans,vector<int> &arr,int n){
    // base case
    if(ind==n){
        ans.push_back(arr);
        return;
    }
    for(int i=ind;i<n;i++){
        swap(arr[ind],arr[i]);
        solve(ind+1,ans,arr,n);
        swap(arr[ind],arr[i]);
    }
}
vector<vector<int>> permute(vector<int>& arr) {
        vector<vector<int>> ans;
        solve(0,ans,arr,arr.size());
        return ans;
    }

// https://leetcode.com/problems/permutations/submissions/1224024307/
int main(){
  
    vector<int> v{1,2,3};
  vector < vector < int >> sum =permute(v);
  cout << "All Permutations are " << endl;
  for (int i = 0; i < sum.size(); i++) {
    for (int j = 0; j < sum[i].size(); j++)
      cout << sum[i][j] << " ";
    cout << endl;
  }
  
return 0;
}