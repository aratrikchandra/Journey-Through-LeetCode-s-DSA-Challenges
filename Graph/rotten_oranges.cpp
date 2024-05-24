#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, 1, 0, -1};
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q; // <<row,col>,time>
        int fresh = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2) // starting points of bfs
                {
                    q.push({{i, j}, 0});
                }
                else if (grid[i][j] == 1) // starting points of bfs
                {
                    fresh++;
                }
            }
        }
        int maxTime = 0;
        int count=0;
        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;

            q.pop();
            maxTime = max(maxTime, time);
            for (int i = 0; i < 4; i++)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                // checking for validity
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m)
                {
                    if (grid[nRow][nCol] == 1 && visited[nRow][nCol] != 2) // important
                    {
                        visited[nRow][nCol] = 2;
                        q.push({{nRow, nCol}, time + 1});
                        count++;
                    }
                }
            }
        }
        if(fresh==count)
        return maxTime;
        else
        return -1;
    }
};

int main()
{

    vector<vector<int>> grid{{0, 1, 2}, {0, 1, 2}, {2, 1, 1}};
    Solution obj;
    int ans = obj.orangesRotting(grid);
    cout << ans << "\n";

    return 0;
}

// https://leetcode.com/problems/rotting-oranges/submissions/1141419581/