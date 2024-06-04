#include <bits/stdc++.h>
using namespace std;

// Note
// We need to Update maxLen and maxInd for every index and should move them outside of the if (dp[prev] + 1 > dp[i]) condition to ensure that they are correctly tracked.
vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
{
    vector<int> ans;
    // edge case
    if(n==0)
    return ans;
    vector<int> dp(n, 1);
    vector<int> parent(n,1);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev <= i - 1; prev++)
        {
            if (arr[prev] < arr[i])
            {
                if (dp[prev] + 1 > dp[i])
                {
                    dp[i] = dp[prev] + 1;
                    parent[i] = prev;
                }
            }
        }
    }
    int maxLen = 0;
    int maxInd = -1;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > maxLen)
        {
            maxLen = dp[i];
            maxInd = i;
        }
    }

    int ind = maxInd;
    ans.push_back(arr[ind]);
    while (ind != parent[ind])
    {
        ind = parent[ind];
        ans.push_back(arr[ind]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
// https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=printing-longest-increasing-subsequence
int main()
{

    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};

    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> temp = longestIncreasingSubsequence(n, arr);

    cout << "The subsequence elements are ";

    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;

    return 0;
}
