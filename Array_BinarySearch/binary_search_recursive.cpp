
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr,int low,int high,int target)
{
    // base case
    if(low>high)
        return -1; // element not found
    
    int mid=low+(high-low)/2;

    if(arr[mid]>target)
        return binarySearch(arr,low,mid-1,target);
    else if(arr[mid]<target)
        return binarySearch(arr,mid+1,high,target);
    else
        return mid;
}

int search(vector<int>& nums, int target) {
    int n=nums.size();
    return binarySearch(nums,0,n-1,target);
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int ind = search(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    return 0;
}

// https://leetcode.com/problems/binary-search/submissions/1174374826/