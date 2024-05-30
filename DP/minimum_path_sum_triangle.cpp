#include <bits/stdc++.h>
using namespace std;

int solve_1(int i, int j, vector<vector<int>> &triangle, int n)
{
    // base case
    if (i == n - 1)
        return triangle[i][j];

    // try out all posiibility
    int bottom = 1e9;
    int rightDiagonal = 1e9;
    bottom = triangle[i][j] + solve_1(i + 1, j, triangle, n);
    rightDiagonal = triangle[i][j] + solve_1(i + 1, j + 1, triangle, n);

    return min(bottom, rightDiagonal);
}
int solve_2(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    // base case
    if (i == n - 1)
        return triangle[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    // try out all posiibility
    int bottom;
    int rightDiagonal;
    bottom = triangle[i][j] + solve_2(i + 1, j, triangle, n, dp);
    rightDiagonal = triangle[i][j] + solve_2(i + 1, j + 1, triangle, n, dp);

    return dp[i][j] = min(bottom, rightDiagonal);
}

int solve_3(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // base case
    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // try out all posiibility
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            // try out all posiibility
            int bottom;
            int rightDiagonal;
            bottom = triangle[i][j] + dp[i + 1][j];
            rightDiagonal = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(bottom, rightDiagonal);
        }
    }
    return dp[0][0];
}
int solve_4(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> front(n, -1);
    // base case
    for (int j = 0; j < n; j++)
    {
        front[j] = triangle[n - 1][j];
    }

    // try out all posiibility
    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> curr(n, -1);
        for (int j = i; j >= 0; j--)
        {
            // try out all posiibility
            int bottom;
            int rightDiagonal;
            bottom = triangle[i][j] + front[j];
            rightDiagonal = triangle[i][j] + front[j + 1];
            curr[j] = min(bottom, rightDiagonal);
        }
        front = curr;
    }
    return front[0];
}
int minimumTotal(vector<vector<int>> &triangle)
{
    // int n=triangle.size();
    // return solve_1(0,0,triangle,n);
    // vector<vector<int>> dp(n,vector<int> (n,-1));
    // return solve_2(0,0,triangle,n,dp);

    // return solve_3(triangle);
    return solve_4(triangle);
}
// https://leetcode.com/problems/triangle/submissions/1268775916/
int main()
{

    return 0;
}