#include <bits/stdc++.h>
using namespace std;

bool searchElement(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int row=0,col=m-1; // starting point

    while(row<n && col>=0)
    {
        int val=matrix[row][col];
        if(val==target)
            return true;
        else if(val<target)
            row++;
        else
            col--;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    searchElement(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}

// https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/1179982397/