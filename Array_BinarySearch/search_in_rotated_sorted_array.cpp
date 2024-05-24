
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int target)
{
    int n=arr.size();
    int low=0;
    int high=n-1;

    while(low<=high)
    {
        int mid=low+(high-low)/2;
        // first check if mid is the index where target lies
        if(arr[mid]==target)
            return mid;
        // check which half is sorted
        if(arr[low]<=arr[mid])  // left half is sorted
        {
            if(arr[low]<=target && target<=arr[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        else  // right half is sorted
        {
            if(arr[mid]<=target && target<=arr[high])
                low=mid+1;
            else
                high=mid-1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 5;
    int ans = search(arr, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}

// https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/1175345222/