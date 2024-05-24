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
int countPartition(vector<int> arr, int maxSum, int n)
{
    int count = 1;
    int currSum = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (currSum + arr[i] <= maxSum)
            currSum += arr[i];
        else
        {
            count += 1; // new partition
            currSum = arr[i];
        }
    }
    return count;
}
int splitArray(vector<int> &arr, int k)
{
    int n = arr.size();
    pair<int, int> val = max_and_sum(arr, n);
    int low = val.first;
    int high = val.second;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int partition = countPartition(arr, mid, n);
        if (partition > k)
        {
            low = mid + 1;
        }
        else if (partition < k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> a = {7, 2, 5, 10, 8};
    int k = 2;
    int ans = splitArray(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}

// https://leetcode.com/problems/split-array-largest-sum/submissions/1178818817/