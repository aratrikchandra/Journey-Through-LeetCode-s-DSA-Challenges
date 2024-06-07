#include <bits/stdc++.h>
using namespace std;

int mod=(1e9)+7;
// tabulation
int countSubsetSumEqualsK(vector<int>& arr, int k, int n)
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
int countPartitions(int n, int d, vector<int>& arr) {
        int sum=0;
        for(int it: arr)
        sum+=it;
        //edge case
        if(sum<d) return 0;
        if((sum-d)%2==1) return 0;

        return countSubsetSumEqualsK(arr,(sum-d)/2,n);
    }
// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=partitions-with-given-difference
int main(){
  
  
  
return 0;
}