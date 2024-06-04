#include <bits/stdc++.h>
using namespace std;

int LongestBitonicSequence(int n, vector<int> &arr) {
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);

        // filling dp1 from left to right
        for(int i=0;i<n;i++){
        for(int prev=0;prev<=i-1;prev++)
        {
            if(arr[prev]<arr[i]){
                if(dp1[prev]+1 > dp1[i])
                {
                    dp1[i]=dp1[prev]+1;
                }
            }
        }
        }

        // filling dp2 from right to left
        for(int i=n-1;i>=0;i--){
        for(int prev=n-1;prev>i;prev--)
        {
            if(arr[prev]<arr[i]){
                if(dp2[prev]+1 > dp2[i])
                {
                    dp2[i]=dp2[prev]+1;
                }
            }
        }
        }
// If the problem states that A bitonic sequence should have both an increasing and a decreasing part. If the array is strictly increasing or strictly decreasing, the longest bitonic subsequence length should be zero in the context of the problem as you described it. To handle this, we need to check if there are both increasing and decreasing parts in the sequence

// dp1[i] > 1 and dp2[i] > 1 is used to confirm there is at least one increasing and one decreasing part at index i

        int maxLen=0;
        for(int i=0;i<n;i++){
            if(dp1[i]>1 && dp2[i]>1)
            maxLen=max(maxLen, dp1[i]+dp2[i]-1);
        }
       return maxLen; 
    }
// https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
int main(){
  
  
  
return 0;
}