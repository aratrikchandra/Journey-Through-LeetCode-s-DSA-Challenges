#include <bits/stdc++.h>
using namespace std;
void solve(int element, int k, int n, vector<int> &ds, vector<vector<int>> &ans)
{
    // base case
    if (k == 0 && n == 0) // valid answer
    {
        ans.push_back(ds);
        return;
    }
    if (k == 0) // invalid answer
        return;
    if(element>9) // element can take value from 1 to 9
    return;
    // non-pick case
    solve(element + 1, k, n, ds, ans);
    // pick case
    if (element <= n)
    {
        ds.push_back(element);
        solve(element + 1, k - 1, n - element, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> ans;
    vector<int> ds;
    solve(1, k, n, ds, ans);
    return ans;
}

// https://leetcode.com/problems/combination-sum-iii/submissions/1224652877/
int main()
{

    vector<vector<int>> sum = combinationSum3(3, 9);
    cout << "All Combinations are " << endl;
    for (int i = 0; i < sum.size(); i++)
    {
        for (int j = 0; j < sum[i].size(); j++)
            cout << sum[i][j] << " ";
        cout << endl;
    }

    return 0;
}