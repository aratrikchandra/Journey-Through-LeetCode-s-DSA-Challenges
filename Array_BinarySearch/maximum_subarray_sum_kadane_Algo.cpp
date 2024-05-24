
#include <bits/stdc++.h>
using namespace std;

    int maxSubArray(vector<int>& arr) {
        int n=arr.size();
        int maxSum=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            maxSum=max(maxSum,sum);  // update maxSum before setting sum to zero
            if(sum<0)
            {
                sum=0;
            }
        }
        return maxSum;
    }

int main()
{
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubArray(arr);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

// https://leetcode.com/problems/maximum-subarray/