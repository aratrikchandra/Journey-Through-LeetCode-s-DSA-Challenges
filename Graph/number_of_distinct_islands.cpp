#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> grid, vector<vector<int>> &visited, vector<pair<int, int>> &res, int baseRow, int baseCol, int delrow[], int delcol[])
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        res.push_back({
            row - baseRow,
             col - baseCol
             });
        // traverses all 4 directions
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            // check for valid coordinates and for land cell
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
            {
                if(visited[nrow][ncol]==0 && grid[nrow][ncol]==1)
                dfs(nrow, ncol, grid, visited, res, baseRow, baseCol, delrow, delcol);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> s;
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, +0, -1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && visited[i][j]==0)  // calling for different components
                {
                    vector<pair<int, int>> res;
                    dfs(i, j, grid, visited, res, i, j, delrow, delcol);
                    s.insert(res);
                }
            }
        }
        return s.size();
    }
};

int main()
{

    vector<vector<int>> grid{
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}};

    Solution obj;
    cout << obj.countDistinctIslands(grid) << endl;
}

// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1