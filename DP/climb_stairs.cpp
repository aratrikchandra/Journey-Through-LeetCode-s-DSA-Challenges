#include <bits/stdc++.h>
using namespace std;

// recursive approach
int solve_1(int ind)
{
    // base case
    if (ind <= 1)
        return ind;

    int oneStep = solve_1(ind - 1);

    int twoStep = solve_1(ind - 2);

    return oneStep + twoStep;
}
// memoized approach
int solve_2(int ind, vector<int> &dp)
{
    // base case
    if (ind <= 1)
        return ind;
    // check if the ans already exists
    if(dp[ind]!=-1) return dp[ind];

    // if the ans does not exist 
    int oneStep = solve_1(ind - 1);

    int twoStep = solve_1(ind - 2);

    return dp[ind]=oneStep + twoStep;
}

// tabulation approach
int solve_3(int n)
{
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int solve_4(int n)
{
    int prev2=0;
    int prev=1;
    int curr=0;
    for(int i=2;i<=n;i++){
        curr=prev+prev2;
        prev2=prev;
        prev=curr;
    }
    return prev;
}
int climbStairs(int n)
{
    // return solve_1(n);

    // vector<int> dp(n+1,-1);
    // return solve_2(n, dp);
    // return solve_3(n);
    return solve_4(n);
}
// https://leetcode.com/problems/climbing-stairs/submissions/1266601524/
int main()
{
    cout<<climbStairs(5);
    return 0;
}