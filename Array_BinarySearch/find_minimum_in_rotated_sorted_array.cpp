
#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // optimization
        if (arr[low] <= arr[mid] && arr[mid] <= arr[high]) // both left and right half are sorted
        {
            // we can combine two arrays into one
            if (arr[low] < ans)
            {
                ans = arr[low];
            }
            break;
        }

        // check which half is sorted
        if (arr[low] <= arr[mid]) // left half is sorted
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
            }
            low = mid + 1;
        }
        else // right half is sorted
        {
            if (arr[mid] < ans)
            {
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 8, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;
}

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/1175365915/