#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    void dfs(int row, int col, vector<vector<char>> mat, vector<vector<int>> &visited)
    {
        int n = mat.size();
        int m = mat[0].size();
        visited[row][col] = 1;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
            {
                if (!visited[nrow][ncol] && mat[nrow][ncol]=='O')
                {
                    dfs(nrow, ncol, mat, visited);
                }
            }
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<char>> ans = mat;
        for (int i = 0; i < n; i++)
        {
            // first column
            if (mat[i][0] == 'O')
            {
                dfs(i, 0, mat, visited);
            }
            // last column
            if (mat[i][m - 1] == 'O')
            {
                dfs(i, m - 1, mat, visited);
            }
        }

        for (int j = 0; j < m; j++)
        {
            // first row
            if (mat[0][j] == 'O')
            {
                dfs(0, j, mat, visited);
            }
            // last row
            if (mat[n - 1][j] == 'O')
            {
                dfs(n - 1, j, mat, visited);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O' && visited[i][j] == 0)
                {
                    ans[i][j] = 'X';
                }
            }
        }
        return ans;
    }
};

int main()
{

    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}};

    Solution ob;
    // n = 5, m = 4
    vector<vector<char>> ans = ob.fill(5, 4, mat);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// https://leetcode.com/problems/surrounded-regions/submissions/1142595839/