

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int val)
{
    int n = arr.size(); // size of the array
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int i, j, k, l;
    for (l = 0; l < n - 3; l++) 
    {
        if (l > 0 && arr[l] == arr[l - 1]) // check boundary conditions
            continue;
        for (i = l + 1; i < n - 2; i++) 
        {
            if (i > l + 1 && arr[i] == arr[i - 1])   // check boundary conditions
                continue;
            j = i + 1;
            k = n - 1;
            while (j < k)
            {
                long long sum = arr[j] + arr[k];
                long long target = (long long)val - arr[l] - arr[i];

                if (sum < target)
                    j++;
                else if (sum > target)
                    k--;
                else
                {
                    vector<int> temp = {arr[l], arr[i], arr[j], arr[k]};
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
    }
    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans)
    {
        cout << "[";
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

// https://leetcode.com/problems/4sum/