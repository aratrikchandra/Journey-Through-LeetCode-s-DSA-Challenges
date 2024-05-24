#include <bits/stdc++.h>
using namespace std;

int missingK(vector < int > arr, int n, int k) {
    int low=0;
    int high=n-1;

    while(low<=high)
    {
        int mid=low+(high-low)/2;

        int missing=arr[mid]-(mid+1);
        if(missing<k)
            low=mid+1;
        else
        {
            high=mid-1;
        }
    }
    // now high points to the number in the array which has < k missing numbers and predeccesor of kth missing number
    return high+1+k; // low+k
}

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}

// https://leetcode.com/problems/kth-missing-positive-number/submissions/1178063171/