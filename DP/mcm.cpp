#include <bits/stdc++.h>
using namespace std;
int solve_1(int i, int j, int N, int arr[])
{
    // base case
    if (i == j)
        return 0;
    int numOfMultiplication = 1e9;
    for (int k = i; k < j; k++)
    {
        numOfMultiplication = min(numOfMultiplication, arr[i - 1] * arr[k] * arr[j] + solve_1(i, k, N, arr) + solve_1(k + 1, j, N, arr));
    }
    return numOfMultiplication;
}
// memoization
int solve_2(int i, int j, int N, int arr[], vector<vector<int>> &dp)
{
    // base case
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    int numOfMultiplication = 1e9;
    for (int k = i; k < j; k++)
    {
        numOfMultiplication = min(numOfMultiplication, arr[i - 1] * arr[k] * arr[j] + solve_2(i, k, N, arr, dp) + solve_2(k + 1, j, N, arr, dp));
    }
    return dp[i][j] = numOfMultiplication;
}
// tabulation
int solve_3(int N, int arr[])
{
    vector<vector<int>> dp(N, vector<int>(N, 0));
    // base case
    for (int i = 0; i < N; i++)
        dp[0][0] = 0;

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int numOfMultiplication = 1e9;
            for (int k = i; k < j; k++)
            {
                numOfMultiplication = min(numOfMultiplication, arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j]);
            }
             dp[i][j] = numOfMultiplication;
        }
    }

    return dp[1][N-1];
}
int matrixMultiplication(int N, int arr[])
{
    // return solve_1(1,N-1,N,arr);
    // vector<vector<int>> dp(N,vector<int> (N,-1));
    // return solve_2(1,N-1,N,arr,dp);
    return solve_3(N,arr);
}
// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=matrix-chain-multiplication
int main()
{

    return 0;
}