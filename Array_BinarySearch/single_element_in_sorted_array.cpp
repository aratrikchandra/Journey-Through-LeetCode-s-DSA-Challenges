#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size(); // size of the array.
    int low = 0;
    int high = n - 1;

    // handle edge cases
    if (n == 1)
        return n;
    if (arr[low] != arr[low + 1])
        return arr[low];
    if (arr[high] != arr[high - 1])
        return arr[high];

    low++; high--;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid - 1] != arr[mid] && arr[mid] != arr[mid + 1]) // arr[mid] is the single element
            return arr[mid];
        // eliminate one half
        if(((mid%2)==1 && arr[mid]==arr[mid-1]) || ((mid%2==0 && arr[mid]==arr[mid+1])))  // we are in left half
        {
            low=mid+1;
        }
        else  // we are in right half
        {
            high=mid-1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = singleNonDuplicate(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;
}

// https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/1177211319/