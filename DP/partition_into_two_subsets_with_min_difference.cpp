#include <bits/stdc++.h>
using namespace std;
   // tabulation
int solve_3(vector<int> &arr, int k, int n)
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
   // now the dp array is ready to be used
   int minDiff=1e9;
   for(int s1=0;s1<=k/2;s1++){
    if(dp[n-1][s1]==true){
        int diff=abs(s1-(k-s1));
        minDiff=min(minDiff,diff);
    }
   }
   return minDiff;
}
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it: nums)
        sum+=it;

        return solve_3(nums,sum,n);
    }
// https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
int main(){
  
  
  
return 0;
}