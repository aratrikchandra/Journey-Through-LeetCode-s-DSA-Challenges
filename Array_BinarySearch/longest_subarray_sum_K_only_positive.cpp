

#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> &a, long long k)
{
    int n = a.size(); // size of the array.
    int left = 0, right = 0;
    long long sum = 0;
    int maxLen = 0;
    while (right < n)
    {
        sum += a[right];
        while (sum > k && left <= right)
        {
            sum = sum - a[left];
            left++;
        }
        if (sum == k)
            maxLen = max(maxLen, right - left +1);
        right++;
    }
    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

// https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION