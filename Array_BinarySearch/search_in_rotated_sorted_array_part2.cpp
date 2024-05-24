
#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // first check if mid is the index where target lies
        if (arr[mid] == target)
            return true;

        // important edge case
        if(arr[low]==arr[mid] && arr[mid]==arr[high])
        {
            low++;
            high--;
            continue;
        }
        // check which half is sorted
        if (arr[low] <= arr[mid]) // left half is sorted
        {
            if (arr[low] <= target && target <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else // right half is sorted
        {
            if (arr[mid] <= target && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 5;
    bool ans = search(arr, k);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";
    return 0;
}

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/submissions/1175353783/