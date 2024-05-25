#include <bits/stdc++.h>
using namespace std;
// space optimization
int solve_4(vector<int> &nums)
{
    int n = nums.size();
    int prev, prev2;

    for (int ind = 0; ind < n; ind++)
    {
        int curr;
        // base case
        if (ind == 0)
        {
            prev = nums[ind];
            continue;
        }
        // non pick case
        int nonPick = 0 + prev;
        // pick case
        int pick = nums[ind];
        if (ind >= 2)
            pick += prev2;
        curr = max(pick, nonPick);

        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    if(n==1)
    return nums[0];
    vector<int> nums1(nums);
    vector<int> nums2(nums);
    // Remove the first element
    if (!nums1.empty())
    {
        nums1.erase(nums1.begin());
    }

    // Remove the last element
    if (!nums2.empty())
    {
        nums2.pop_back();
    }
    return max(solve_4(nums1), solve_4(nums2));
}

// https://leetcode.com/problems/house-robber-ii/submissions/1267398209/
int main()
{

    return 0;
}