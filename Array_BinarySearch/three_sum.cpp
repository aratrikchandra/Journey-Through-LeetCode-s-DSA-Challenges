#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int i, j, k;
    for (i = 0; i < n - 2; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        j = i + 1;
        k = n - 1;
        while (j < k)
        {
            int sum = arr[j] + arr[k];
            int target = 0 - arr[i];

            if (sum < target)
                j++;
            else if (sum > target)
                k--;
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;

            while (j < k && arr[j] == arr[j - 1]) // to find only unique triplets
                j++;
            while (j < k && arr[k] == arr[k + 1]) // to find only unique triplets
                k--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {13, -18, 0 ,30 ,0 ,-48, 0 ,-34,-27,-40,-4,-17,-30,-2};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans)
    {
        cout << "[";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}


// https://leetcode.com/problems/3sum/submissions/1169057955/