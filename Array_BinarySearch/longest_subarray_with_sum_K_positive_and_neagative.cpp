#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(int arr[], int n, int k)
{
    // <sum,index>
           unordered_map<int, int> umap;
    int preSum = 0;
    int len = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        if (umap.find(preSum) == umap.end()) // if the value "preSum is not present in the map then only insert"
        {                                   // needed if the array contains negative numbers or zeroes
            umap[preSum] = i;
        }
        if (preSum == k)
            maxLen=max(maxLen,i+1);

        if (umap.find(preSum - k) != umap.end())
        {
            int ind = umap[preSum - k];
            len = i - ind;
            maxLen=max(len,maxLen);
        }
        
    }
    return maxLen;
}

int main()
{
    int a[] = {2, 3, 5, 1, 9};
    int k = 10;
    int len = getLongestSubarray(a, 5, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}


// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1