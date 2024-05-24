#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int first = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target)
            high = mid - 1;
        else if (arr[mid] < target)
            low = mid + 1;
        else
        {
            first = mid;
            high = mid - 1;
        }
    }
    return first;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int maxCount=0;
    int maxIndex=-1;
    for(int i=0;i<n;i++)
    {
        int count=m-firstOccurence(matrix[i],m,1);
        if(count>maxCount)
        {
            maxCount=count;
            maxIndex=i;
        }
    }
    return maxIndex;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " <<
         rowWithMax1s(matrix, n, m) << '\n';
}

// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1