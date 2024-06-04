#include <bits/stdc++.h>
using namespace std;
int findNumberOfLIS(vector<int> &arr)
{

    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> count(n, 1);
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev <= i - 1; prev++)
        {
            if (arr[prev] < arr[i])
            {
                if (dp[prev] + 1 > dp[i])
                {
                    dp[i] = dp[prev] + 1;
                    count[i] = count[prev]; // new LIS
                }
                else if (dp[prev] + 1 == dp[i])
                {
                    count[i] = count[i] + count[prev];
                }
            }
        }
        maxLen = max(maxLen, dp[i]);
    }

    int ans = 0;
    // if multiple cells in dp[] has the maximum value then sum up  all the count
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxLen)
        {
            ans = ans + count[i];
        }
    }
    return ans;
}
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/submissions/1277763378/
int main()
{

    return 0;
}