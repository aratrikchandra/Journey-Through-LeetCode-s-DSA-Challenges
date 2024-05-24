#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, 1, 0, -1};

        // multi source bfs

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;

            dist[row][col]=step;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                {
                    if (!visited[nrow][ncol])
                    {
                        q.push({{nrow,ncol},step+1});
                        visited[nrow][ncol]=1;
                    }
                }
            }
        }
        return dist;
    }
};

int main()
{
    vector<vector<int>> grid{
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1}};

    Solution obj;
    vector<vector<int>> ans = obj.nearest(grid);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }

    return 0;
}

// https://leetcode.com/problems/01-matrix/submissions/1142599961/