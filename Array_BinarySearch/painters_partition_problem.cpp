#include <bits/stdc++.h>
using namespace std;
pair<int, int> max_and_sum(vector<int> arr, int n)
{
    int max = arr[0];
    int sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
        sum += arr[i];
    }
    return make_pair(max, sum);
}
int countPainter(vector<int> arr, int maxUnit, int n)
{
    int count=1;
    int currUnit=arr[0];

    for(int i=1;i<n;i++)
    {
        if(currUnit+arr[i]<=maxUnit)
            currUnit+=arr[i];
        else{
            count++;
            currUnit=arr[i];
        }
    }
    return count;
}
int findLargestMinDistance(vector<int> arr, int k)
{
    int n=arr.size();
    pair<int, int> val = max_and_sum(arr, n);
    // when ans is not possible
    if (n < k)
        return -1;
    int low = val.first;
    int high = val.second;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int painter = countPainter(arr, mid, n);

        if (painter <= k) // possible to allocate
            high=mid-1;
        else
            low=mid+1;
    }
    return low;
}
int main()
{
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << findLargestMinDistance(arr,k);
    return 0;
}

// https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION