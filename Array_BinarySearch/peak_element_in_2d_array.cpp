#include <bits/stdc++.h>
using namespace std;
int maxAtCol(vector<vector<int>> mat, int col, int n)
{
    int maxVal = INT_MIN;
    int maxIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][col] > maxVal)
        {
            maxVal = mat[i][col];
            maxIndex = i;
        }
    }
    return maxIndex;
}
vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = m - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int ind = maxAtCol(mat, mid, n);
        int left = mid == 0 ? -1 : mat[ind][mid - 1];
        int right = mid == m - 1 ? -1 : mat[ind][mid + 1];
        if (left < mat[ind][mid] && mat[ind][mid] > right) // peak element found
            return {ind, mid};
        if (left < mat[ind][mid])
            low = mid + 1;
        else if (mat[ind][mid] > right)
            high = mid - 1;
        else
        {
            low = mid + 1; // if mat has multiple peak elements
        }
    }
    return {-1, -1};
}
int main()
{

    vector<vector<int>> mat = {{10, 20, 15},
                               {21, 30, 14},
                               {7, 16, 32}};
    vector<int> ans = findPeakGrid(mat);
    cout << "peak element is at: (" << ans[0] << "," << ans[1] << ")";
    return 0;
}
// https://leetcode.com/problems/find-a-peak-element-ii/submissions/1181096820/