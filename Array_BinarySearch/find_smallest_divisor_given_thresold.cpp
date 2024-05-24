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
int sumByD(vector<int> &nums, int divisor, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + ceil((double)nums[i] / divisor);
    }
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold)
{
    int n = nums.size();
    // edge case when soln not possible
    if (n > threshold)
        return -1;
    int low = 1;
    int high = maxi(nums, n);
    // int ans=INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int sum = sumByD(nums, mid, n);
        if (sum <= threshold)
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
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}

// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/submissions/1176996545/