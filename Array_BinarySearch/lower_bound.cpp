
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int target) {
    int low = 0;
    int high = n - 1;
    int ans=n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target){
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
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = lowerBound(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}

// https://www.codingninjas.com/studio/problems/lower-bound_8165382?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION