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
int countDays(vector<int> weights,int capacity,int n)
{
    int days=1;
    int load=0;
    for(int i=0;i<n;i++)
    {
        if(load+weights[i]<=capacity)
        {
            load=load+weights[i];
        }
        else{
        days=days+1;
        load=weights[i];
        }
    }
    return days;
} 
int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    pair<int, int> val = max_and_sum(weights, n);
    int low = val.first;
    int high = val.second;
    int ans = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int d = countDays(weights, mid,n);

        if (d <= days)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = shipWithinDays(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}

// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/submissions/1177854194/