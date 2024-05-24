#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &arr, int target)
{
    int n = arr.size();

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target)
            high = mid - 1;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

// better approach
bool searchMatrix1(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] <= target && matrix[i][m - 1] >= target) // we will apply binary search only when this cond satisfies
        {
            if (binarySearch(matrix[i], target) != -1)
                return true;
        }
    }
    return false;
}
// https://leetcode.com/problems/search-a-2d-matrix/submissions/1179977337/

// optimal approach
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high = n * m - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int row = mid / m;
        int col = mid % m;

        int val = matrix[row][col];
        if (val == target)
            return true;
        else if (val < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
int main()
{
    //vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<vector<int>> matrix ={{1,4},{2,5}};
    searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}

// https://leetcode.com/problems/search-a-2d-matrix/submissions/1179976266/