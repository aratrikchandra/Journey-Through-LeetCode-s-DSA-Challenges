#include <bits/stdc++.h>
using namespace std;
void solve(int ind, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr, int n)
{

    // put in final answer
    ans.push_back(ds);

    for (int i = ind; i < n; i++)
    {
        if (i != ind && arr[i - 1] == arr[i]) // skip duplicate element
            continue;

        ds.push_back(arr[i]);
        // recursive call
        solve(i + 1, ds, ans, arr, n);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &arr)
{
    vector<int> ds;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    solve(0, ds, ans, arr, arr.size());
    return ans;
}
int main()
{

    return 0;
}
// https://leetcode.com/problems/subsets-ii/submissions/1223351224/