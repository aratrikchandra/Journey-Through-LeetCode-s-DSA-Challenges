#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        // finding sources
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1)
                    fresh++;
            }
        }
        int dr[] = {0, 0, -1, 1};
        int dc[] = {1, -1, 0, 0};
        int timer = 0;
        int newlyRotten=0;
        while (!q.empty()) {
            int size = q.size();
            bool flag = false; // for each level we have flag
            for (int count = 0; count < size; count++) {
                auto it = q.front();
                q.pop();
                int row = it.first;
                int col = it.second;

                for (int i = 0; i < 4; i++) {
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];
                    // check array out of bound
                    if (newRow >= 0 && newRow < n && newCol >= 0 &&
                        newCol < m) {
                        if (grid[newRow][newCol] == 1) {
                            q.push({newRow, newCol});
                            grid[newRow][newCol] = 2;
                            flag = true;
                            newlyRotten++;
                        }
                    }
                }
            }
            if(flag)
            timer++;
        }
        if(fresh==newlyRotten)
        return timer;
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

// https://leetcode.com/problems/rotting-oranges/submissions/1290800145/