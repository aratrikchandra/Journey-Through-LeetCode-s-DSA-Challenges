#include <bits/stdc++.h>
using namespace std;
int maxFrequency(vector<int> &nums, int k)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = 0;
    long long total = 0;
    int maxWindow = 0;
    while (right < n)
    {

        total += nums[right];

        // invalid window
         while (left <= right && (long long)(right - left + 1) * nums[right] > total + (long long)k)
        {
            total -= nums[left];
            left++;
        }

        maxWindow = max(maxWindow, right - left + 1);
        right++;
    }
    return maxWindow;
}
// https://leetcode.com/problems/frequency-of-the-most-frequent-element/submissions/1288686905/
int main()
{

    return 0;
}