
#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int n) {
    vector<int> ans;

    long long prev=1;
    // we will total have n elements in row n
    ans.push_back(1);

    for(int i=1;i<n;i++)
    {
        prev= prev * (n-i);
        prev=prev/i;
        ans.push_back(prev);
    }
    return ans;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for(int i=1;i<=n;i++)
    {
        ans.push_back(generateRow(i));
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}

// https://leetcode.com/problems/pascals-triangle/submissions/1168972305/