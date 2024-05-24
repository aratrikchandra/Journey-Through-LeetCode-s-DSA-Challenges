#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        int n = grid.size();
        int m = grid[0].size();
        // edge case
        if(source.first==destination.first && source.second==destination.second)  // if src is the dest itself
        return 0;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int, int>>> q; // queue will work here, we don't need priority queue as distances are in inc order

        q.push({0, {source.first, source.second}}); // src is (0,0) and dest is (n-1,m-1)
        dist[source.first][source.second] = 0;

        int dr[]={0,0,+1,-1};
        int dc[]={-1,+1,0,0};

        while (!q.empty())
        {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;

            q.pop();

                for(int i=0;i<4;i++)
                {
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];

                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1)
                    {
                            if (dis + 1 < dist[newRow][newCol])
                            {
                                dist[newRow][newCol] = dis + 1;
                                if (newRow == destination.first && newCol == destination.second)
                                {
                                    return dis+1;
                                }
                                q.push({dist[newRow][newCol], {newRow, newCol}});
                            }
                    }
                }
            }
        return -1;
    }
};

int main()
{
    // Driver Code.

    pair<int, int> source, destination;
    source.first = 0;
    source.second = 1;
    destination.first = 2;
    destination.second = 2;

    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};

    Solution obj;

    int res = obj.shortestPath(grid,source,destination);

    cout << res;
    cout << endl;

    return 0;
}

// https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze