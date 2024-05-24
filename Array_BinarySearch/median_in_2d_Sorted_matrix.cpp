#include <bits/stdc++.h>
using namespace std;
pair<int, int> min_maxAtCol(vector<vector<int>> mat, int n, int m)
{
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][m - 1] > maxVal)
        {
            maxVal = mat[i][m - 1];
        }
        if (mat[i][0] < minVal)
        {
            minVal = mat[i][0];
        }
    }
    return make_pair(minVal, maxVal);
}
int upperBound(vector<int> &arr, int target, int n)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int countSmaller(vector<vector<int>> mat, int k)
{
    int n = mat.size();
    int m = mat[0].size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        count+=upperBound(mat[i],k,m);
    }
    return count;
}
int findMedian(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    pair<int, int> val = min_maxAtCol(mat, n, m);
    int low = val.first;
    int high = val.second;
    int req=(n*m)/2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int count = countSmaller(mat,mid);
        if(count<=req) // cant be median
            low=mid+1;
        else{
            high=mid-1; // may be a median
        }
    }
    return low;
}
int main()
{
    int row = 3, col = 3;
    vector<vector<int>> arr = {{1, 3, 8},
                               {2, 3, 4},
                               {1, 2, 5}};
    cout << "The median of the row-wise sorted matrix is: " << findMedian(arr) << endl;
    return 0;
}
// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1