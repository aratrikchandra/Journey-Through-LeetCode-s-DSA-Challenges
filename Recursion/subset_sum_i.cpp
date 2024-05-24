#include <bits/stdc++.h>
using namespace std;
void solve(int ind,int sum,vector<int> &ans,vector<int> &arr,int n){
    // base case
    if(ind==n){
        ans.push_back(sum);
		return;
    }

    // non pick case
    solve(ind+1,sum,ans,arr,n);

    // pick case
    sum+=arr[ind];
    solve(ind+1,sum,ans,arr,n);
    sum-=arr[ind];
}
vector<int> subsetSum(vector<int> &arr){
		vector<int> ans;
        int sum=0;
        solve(0,sum,ans,arr,arr.size());
		sort(ans.begin(),ans.end());
        return ans;
}
int main(){
  
  
  
return 0;
}
// https://www.naukri.com/code360/problems/subset-sum_3843086?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION