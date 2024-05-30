#include <bits/stdc++.h>
using namespace std;
// recursive approach
int solve_1(int day, int last, vector<vector<int>> &points, int n)
{
    // base case
    if (day == 0)
    {
        int maxi = -1e9;
        for (int task = 0; task <= 2; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[day][task]);
            }
        }
        return maxi;
    }

    // try out all possibility
    int maxi = -1e9;
    for (int task = 0; task <= 2; task++)
    {
        if (task != last)
        {
            maxi = max(maxi, points[day][task] + solve_1(day - 1, task, points, n));
        }
    }
    return maxi;
}
// memoization
int solve_2(int day, int last, vector<vector<int>> &points, int n, vector<vector<int>> &dp)
{
    // base case
    if (day == 0)
    {
        int maxi = -1e9;
        for (int task = 0; task <= 2; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[day][task]);
            }
        }
        return maxi;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    // try out all possibility
    int maxi = -1e9;
    for (int task = 0; task <= 2; task++)
    {
        if (task != last)
        {
            maxi = max(maxi, points[day][task] + solve_2(day - 1, task, points, n, dp));
        }
    }
    return dp[day][last] = maxi;
}
// tabulation
int solve_3(vector<vector<int>> &points, int n)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    // base case
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    // try out all possibility
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last <= 3; last++)
        {
            int maxi = -1e9;
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    maxi = max(maxi, points[day][task] + dp[day-1][task]);
                }
            }
            dp[day][last] = maxi;
        }
    }
    return dp[n-1][3];
}
// space optimization
int solve_4(vector<vector<int>> &points, int n)
{
    vector<int> prev(4, -1);
    // base case
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][1], points[0][0]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    // try out all possibility
    for (int day = 1; day < n; day++)
    {
        vector<int> curr(4,-1);
        for (int last = 0; last <= 3; last++)
        {
            int maxi = -1e9;
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    maxi = max(maxi, points[day][task] + prev[task]);
                }
            }
            curr[last] = maxi;
        }
        prev=curr;
    }
    return prev[3];
}
int maximumPoints(vector<vector<int>> &points, int n)
{
    //    return solve_1(n-1,3,points,n);
    // vector<vector<int>> dp(n, vector<int>(4, -1));
    // return solve_2(n - 1, 3, points, n, dp);

    return solve_3(points,n);
}
// https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training
int main()
{

    return 0;
}