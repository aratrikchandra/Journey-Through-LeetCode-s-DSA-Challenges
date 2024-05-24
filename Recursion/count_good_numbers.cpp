#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

// using basic recursion and backtracking
int solve(int ind, int n, vector<int> &ds, vector<vector<int>> &ans)
{
    // base case
    if (ind == n)
    {
        ans.push_back(ds);
        return 1;
    }

    int count = 0;
    if (ind % 2 == 0)
    {
        int nums[] = {0, 2, 4, 6, 8};
        for (int i = 0; i < 5; i++)
        {
            ds.push_back(nums[i]);
            count += solve(ind + 1, n, ds, ans);
            ds.pop_back();
        }
    }
    else
    {
        int nums[] = {2,3,5,7};
        for (int i = 0; i < 4; i++)
        {
            ds.push_back(nums[i]);
            count += solve(ind + 1, n, ds, ans);
            ds.pop_back();
        }
    }
    return count;
}
int countGoodNumbers(long long n)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int count=solve(0,n,ds,ans);

    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[0].size();j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return count;
}

// optimized approach
long pow1(int x, long long n)
{
    // base case
    if (n == 0)
        return 1;

    long temp = pow1(x, n / 2);
    temp = (temp * temp) % mod;
    if (n & 1)
        return (temp * x) % mod;
    else
        return temp;
}

int countGoodNumbers1(long long n)
{
    long even = pow1(5, (n + 1) / 2) % mod;
    long odd = pow1(4, n / 2) % mod;

    return (int)(((even % mod) * (odd % mod)) % mod);
}
// https://leetcode.com/problems/count-good-numbers/
int main()
{
    cout<<countGoodNumbers(4);
    return 0;
}