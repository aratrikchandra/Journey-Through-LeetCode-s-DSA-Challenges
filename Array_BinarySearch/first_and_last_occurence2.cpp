
#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target)
            high = mid - 1;
        else if (arr[mid] < target)
            low = mid + 1;
        else
        {
            first = mid;
            high = mid - 1;
        }
    }
    return first;
}
int lastOccurence(vector<int> &arr, int n, int target)
{
    int n = arr.size();

    int low = 0;
    int high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target)
            high = mid - 1;
        else if (arr[mid] < target)
            low = mid + 1;
        else
        {
            last = mid;
            low = mid + 1;
        }
    }
    return last;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> ans;
    int first = firstOccurence(nums, n, target);
    if (first==-1) // item not present in the array
    {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    int last = lastOccurence(nums, n, target);
    ans.push_back(first);
    ans.push_back(last);
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

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/1174452525/