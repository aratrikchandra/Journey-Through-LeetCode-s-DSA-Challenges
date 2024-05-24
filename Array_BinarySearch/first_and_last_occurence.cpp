
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int upperBound(vector<int> &arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> ans;
    int lb = lowerBound(nums, n, target);
    if (lb == n || nums[lb] != target) // item not present in the array
    {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    int ub = upperBound(nums, n, target);
    ans.push_back(lb);
    ans.push_back(ub - 1);
    return ans;
}

int main()
{
    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, k = 8;
    vector<int> ans = searchRange(arr, k);
    cout << "The first and last positions are: "
         << ans[0] << " " << ans[1] << "\n";
    return 0;
}

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/1174444027/