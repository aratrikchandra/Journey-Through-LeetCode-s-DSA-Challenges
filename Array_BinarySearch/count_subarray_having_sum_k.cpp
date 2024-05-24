
#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
     int n=arr.size();
        map<long long,int> map;
        long long sum=0;
        int count=0;
        map[0]=1; // for handling edge case
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            count+=map[sum-k];

            map[sum]++;
        }
        return count;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}

// https://leetcode.com/problems/subarray-sum-equals-k/