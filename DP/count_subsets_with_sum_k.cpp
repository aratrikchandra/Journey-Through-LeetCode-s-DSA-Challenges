#include <bits/stdc++.h>
using namespace std;
int mod=(1e9)+7;
int solve_1(int ind, int target, int arr[], int n)
{
    // base case
    if (ind == 0){
        if(target==0){
            if(arr[0]==0)
            return 2;
            else
            return 1;
        }
        else{
            if(target==arr[0])
            return 1;
            else
            return 0;
        }

    }

    // try out all possibility
    int notTake = solve_1(ind - 1, target, arr, n);

    int take = 0;
    // edge case
    if (arr[ind] <= target)
        take = solve_1(ind - 1, target - arr[ind], arr, n);

    return take + notTake;
}
// memoization
int solve_2(int ind, int target, int arr[], int n, vector<vector<int>> &dp)
{
    // base case
    if (ind == 0){
        if(target==0){
            if(arr[0]==0)
            return 2;
            else
            return 1;
        }
        else{
            if(target==arr[0])
            return 1;
            else
            return 0;
        }

    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    // try out all possibility
    int notTake = solve_2(ind - 1, target, arr, n, dp)%mod;

    int take = 0;
    // edge case
    if (arr[ind] <= target)
        take = solve_2(ind - 1, target - arr[ind], arr, n, dp)%mod;

    return dp[ind][target] = (take+notTake)%mod;
}
// tabulation
int solve_3(int arr[], int k, int n)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    // base case
    dp[0][0]=(arr[0]==0)?2:1;

    if(arr[0]!=0 && arr[0]<=k) dp[0][arr[0]]=1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= k; target++)
        {
            // try out all possibility
            int notTake = dp[ind - 1][target];

            int take = 0;
            // edge case
            if (arr[ind] <= target)
                take = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = (take+notTake)%mod;
        }
    }
    return dp[n - 1][k];
}
// space optimization
int solve_4(int arr[], int k, int n)
{
    vector<int> prev(k + 1, 0), curr(k+1,0);
    // base case
    prev[0]=(arr[0]==0)?2:1;

    if(arr[0]!=0 && arr[0]<=k) prev[arr[0]]=1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= k; target++)
        {
            // try out all possibility
            int notTake = prev[target];

            int take = 0;
            // edge case
            if (arr[ind] <= target)
                take = prev[target - arr[ind]];

            curr[target] = (take+notTake)%mod;
        }
        prev=curr;
    }
    return prev[k];
}
int perfectSum(int arr[], int n, int target)
	{
    // return solve_1(n-1,target,arr,n);
    // vector<vector<int>> dp(n,vector<int>(target+1,-1));
    // return solve_2(n-1,target,arr,n,dp);
    return solve_4(arr, target, n);
	}
// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem
int main(){
  
  
  
return 0;
}