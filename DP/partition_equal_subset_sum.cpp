#include <bits/stdc++.h>
using namespace std;
   // tabulation
bool solve_3(vector<int> &arr, int k, int n)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    // base case
    for (int ind = 0; ind < n; ind++)
        dp[ind][0] = true;
    // need to avoid array out of bound
    if(arr[0]<=k) dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            // try out all possibility
            bool notTake = dp[ind - 1][target];

            bool take = false;
            // edge case
            if (arr[ind] <= target)
                take = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = take | notTake;
        }
    }
    return dp[n - 1][k];
}

bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it: nums)
        sum+=it;

        if(sum%2)
        return false;
        else
        return solve_3(nums,sum/2,n);
    }
// https://leetcode.com/problems/partition-equal-subset-sum/
int main(){
  
  
  
return 0;
}