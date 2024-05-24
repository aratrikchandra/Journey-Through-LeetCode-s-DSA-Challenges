#include <bits/stdc++.h>
using namespace std;

int maxi(vector<int> arr, int n)
{
    int ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (ans < arr[i])
            ans = arr[i];
    }
    return ans;
}
int calculateHour(vector<int> &piles, int rate, int n, int h)
{
    int hour = 0;
    for (int i = 0; i < n; i++)
    {
        hour = hour + ceil((double)piles[i] / rate);
        if (hour > h)
            break;
    }
    return hour;
}

int minEatingSpeed(vector<int> piles, int h)
{
    int n = piles.size();
    // edge case when soln not possible
    if (n > h)
        return -1;
    int low = 1;
    int high = maxi(piles, n);
    // int ans=INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int totalHours = calculateHour(piles, mid, n, h);
        if (totalHours <= h)
        {
            // ans=mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    // return ans;
    return low;
}
int main()
{
    vector<int> v = {17,12,87};
    int h = 2;
    int ans = minEatingSpeed(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}

// https://leetcode.com/problems/koko-eating-bananas/