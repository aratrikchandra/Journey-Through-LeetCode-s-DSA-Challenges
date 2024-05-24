#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
void bfs(int row,int col,vector<vector<int>> &visited,vector<vector<char>>& grid)
{
    int n=grid.size();
    int m=grid[0].size();

    queue<pair<int,int>> q;

    q.push({row,col});
    visited[row][col]=1;

    while(!q.empty())
    {
        int row=q.front().first;
        int col=q.front().second;

        q.pop();

        // exploring the adjacent nodes of the given node
        for(int delRow=-1;delRow<=1;delRow++)
        {
            for(int delCol=-1;delCol<=1;delCol++)
            {
                int nRow=row+delRow;
                int nCol=col+delCol;

                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]=='1') // grid[nRow][nCol] is a valid neighbour of grid[row][col]
                {
                    if(!visited[nRow][nCol])
                    {
                        q.push({nRow,nCol});
                        visited[nRow][nCol]=1;
                    }
                }
            }
        }
    }
}
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
      int n=grid.size();
      int m=grid[0].size();

      vector<vector<int>> visited(n,vector<int> (m,0));
    int count=0;
      for(int row=0;row<n;row++)
      {
        for(int col=0;col<m;col++)
        {
            if(grid[row][col]=='1' && !visited[row][col])
            {
                bfs(row,col,visited,grid);
                count++;
            }
        }
      }
      return count;
    }
};

int main() {
    // n: row, m: column
    vector<vector<char>> grid
    {
        {'0', '1', '1', '1', '0', '0', '0'},
        {'0', '0', '1', '1', '0', '1', '0'}
    };

        
    Solution obj;
    cout << obj.numIslands(grid) << endl;
        
    return 0;
}

// https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands