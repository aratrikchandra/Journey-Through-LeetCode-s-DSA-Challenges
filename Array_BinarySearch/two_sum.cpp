#include <bits/stdc++.h>
using namespace std;

// using two pointers for variant 1(index not required)

string read(int n, vector<int> arr, int target)
{
    // index not required
    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int sum = arr[left] + arr[right];
        if (sum < target)
            left++;
        else if (sum > target)
            right--;

        else
            return "YES";
    }

    return "NO";
}
// https://www.codingninjas.com/studio/problems/reading_6845742?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION

// using hashing for variant 2(index required)
vector<int> twoSum(vector<int> &arr, int target)
{
    // Write your code here.
    int n = arr.size();
    map<int, int> hash;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int rem = target - arr[i];
        if (hash.find(rem) != hash.end())
        {
            ans.push_back(i);
            ans.push_back(hash[rem]);
        }
        hash[arr[i]] = i;
    }
    if (ans.size() == 0)
        return {-1, -1};
    else
        return ans;
}
// https://leetcode.com/problems/two-sum/submissions/1164185178/

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum(arr, target);
    for (auto it : ans)
        cout << it << endl;
    return 0;
}