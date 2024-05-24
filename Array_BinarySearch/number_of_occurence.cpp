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


int count(vector<int>& arr, int n, int x) {
    int first = firstOccurence(arr, n, x);
    if (first==-1) // item not present in the array
    {
        return 0;
    }
    int last = lastOccurence(arr, n, x);
    return last-first+1;
}

// https://www.codingninjas.com/studio/problems/occurrence-of-x-in-a-sorted-array_630456?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTabValue=SUBMISSION