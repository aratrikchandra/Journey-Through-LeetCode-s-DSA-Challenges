#include <bits/stdc++.h>
using namespace std;

#define ll long long
int mod = (1e3) + 3;
// recursive approach
int solve_1(int i, int j, int isTrue, string &s, int n)
{
    // base case 1
    if (i > j)
        return 0;
    // base case 2
    if (i == j)
    {
        if (isTrue)
        {
            return s[i] == 'T';
        }
        else
        {
            return s[i] == 'F';
        }
    }
    ll ways = 0;
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        ll leftTrue = solve_1(i, k - 1, 1, s, n) % mod;
        ll leftFalse = solve_1(i, k - 1, 0, s, n) % mod;
        ll rightTrue = solve_1(k + 1, j, 1, s, n) % mod;
        ll rightFalse = solve_1(k + 1, j, 0, s, n) % mod;

        if (s[k] == '&')
        {
            if (isTrue)
                ways = (ways + (leftTrue * rightTrue) % mod) % mod;
            else
                ways = (ways + ((leftFalse * rightFalse) % mod + (leftFalse * rightTrue) % mod + (leftTrue * rightFalse) % mod) % mod) % mod;
        }
        else if (s[k] == '|')
        {
            if (isTrue)
                ways = (ways + ((leftTrue * rightTrue) % mod + (leftFalse * rightTrue) % mod + (leftTrue * rightFalse) % mod) % mod) % mod;
            else
                ways = (ways + (leftFalse * rightFalse) % mod) % mod;
        }
        else if (s[k] == '^')
        {
            if (isTrue)
                ways = (ways + ((leftFalse * rightTrue) % mod + (leftTrue * rightFalse) % mod) % mod) % mod;
            else
                ways = (ways + ((leftTrue * rightTrue) % mod + (leftFalse * rightFalse) % mod) % mod) % mod;
        }
    }
    return (int)ways;
}
// memoization
int solve_2(int i, int j, int isTrue, string &s, int n, vector<vector<vector<ll>>> &dp)
{
    // base case 1
    if (i > j)
        return 0;
    // base case 2
    if (i == j)
    {
        if (isTrue)
        {
            return s[i] == 'T';
        }
        else
        {
            return s[i] == 'F';
        }
    }
    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
    
    ll ways = 0;
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        ll leftTrue = solve_2(i, k - 1, 1, s, n,dp) % mod;
        ll leftFalse = solve_2(i, k - 1, 0, s, n,dp) % mod;
        ll rightTrue = solve_2(k + 1, j, 1, s, n,dp) % mod;
        ll rightFalse = solve_2(k + 1, j, 0, s, n,dp) % mod;

        if (s[k] == '&')
        {
            if (isTrue)
                ways = (ways + (leftTrue * rightTrue) % mod) % mod;
            else
                ways = (ways + ((leftFalse * rightFalse) % mod + (leftFalse * rightTrue) % mod + (leftTrue * rightFalse) % mod) % mod) % mod;
        }
        else if (s[k] == '|')
        {
            if (isTrue)
                ways = (ways + ((leftTrue * rightTrue) % mod + (leftFalse * rightTrue) % mod + (leftTrue * rightFalse) % mod) % mod) % mod;
            else
                ways = (ways + (leftFalse * rightFalse) % mod) % mod;
        }
        else if (s[k] == '^')
        {
            if (isTrue)
                ways = (ways + ((leftFalse * rightTrue) % mod + (leftTrue * rightFalse) % mod) % mod) % mod;
            else
                ways = (ways + ((leftTrue * rightTrue) % mod + (leftFalse * rightFalse) % mod) % mod) % mod;
        }
    }
    return dp[i][j][isTrue]= (int)ways;
}
int countWays(int n, string s)
{
    // return solve_1(0, n - 1, 1, s, n);
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>> (n, vector<ll> (2,-1)));
    return solve_2(0, n - 1, 1, s, n,dp);
}
int main()
{

    return 0;
}