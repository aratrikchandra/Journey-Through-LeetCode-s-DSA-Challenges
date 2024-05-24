
#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int target, int n) {
       int low = 0;
    int high = n - 1;
    int ans=n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target){
            ans=mid;
            high=mid-1;
        }
        else 
            low=mid+1;
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 5, 8, 9, 15, 19};
    int n = 6, x = 9;
    int ind = upperBound(arr, x, n);
    cout << "The upper bound is the index: " << ind << "\n";
    return 0;
}

// https://www.codingninjas.com/studio/problems/implement-upper-bound_8165383?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTabValue=SUBMISSION