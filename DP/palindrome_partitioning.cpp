#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;

        i++;
        j--;
    }
    return true;
}
// recursive approach
int solve_1(int i, string s, int n)
{
    // base case
    if (i == n)
        return 0;
    int numOfPartition = 1e9;
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, s))
        {
            numOfPartition = min(numOfPartition, 1 + solve_1(j + 1, s, n));
        }
    }
    return numOfPartition;
}
// memoization
int solve_2(int i, string &s, int n, vector<int> &dp)
{
    // base case
    if (i == n)
        return 0;

    if (dp[i] != -1)
        return dp[i];
    int numOfPartition = 1e9;
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, s))
        {
            numOfPartition = min(numOfPartition, 1 + solve_2(j + 1, s, n, dp));
        }
    }
    return dp[i] = numOfPartition;
}
// tabulation
int solve_3(string &s)
{
    int n = s.size();
    vector<int> dp(n + 1, -1);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int numOfPartition = 1e9;
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
            {
                numOfPartition = min(numOfPartition, 1 + dp[j + 1]);
            }
        }
        dp[i] = numOfPartition;
    }
    return dp[0] - 1;
}
int minCut(string s)
{
    int n = s.size();
    //   return solve_1(0,s,n)-1;
    // vector<int> dp(n + 1, -1);
    // return solve_2(0, s, n, dp) - 1;

    return solve_3(s);
}
// https://leetcode.com/problems/palindrome-partitioning-ii/submissions/1279342252/
int main()
{

    return 0;
}