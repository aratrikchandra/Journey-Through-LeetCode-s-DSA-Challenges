#include <bits/stdc++.h>
using namespace std;


class DisjointSet
{
    public:
vector<int> rank, parent, size;
public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, -1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            // size[i] = 1;
        }
    }

    int findPar(int node)
    {
        if (parent[node] == node) // node is the ultimate parent
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int u_par = findPar(u);
        int v_par = findPar(v);
        // check if they are in same component or not
        if (u_par == v_par)
            return;
        int u_rank = rank[u_par];
        int v_rank = rank[v_par];

        if (u_rank < v_rank)
        {
            parent[u_par] = v_par;
        }
        else if (v_rank < u_rank)
        {
            parent[v_par] = u_par;
        }
        else
        {
            parent[v_par] = u_par;
            rank[u_par] += 1;
        }
    }

    void unionBySize(int u, int v)
    {
        int u_par = findPar(u);
        int v_par = findPar(v);
        // check if they are in same component or not
        if (u_par == v_par)
            return;
        int u_size = size[u_par];
        int v_size = size[v_par];

        if (u_size < v_size)
        {
            parent[u_par] = v_par;
            size[v_par] += size[u_par];
        }
        else
        {
            parent[v_par] = u_par;
            size[u_par] += size[v_par];
        }
    }
};

class Solution
{
private:
    bool isValid(int newr, int newc, int n)
    {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }

public:
    int MaxConnection(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n * n);

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                    continue;

                int dr[] = {-1, +1, 0, 0};
                int dc[] = {0, 0, -1, +1};

                for (int i = 0; i < 4; i++)
                {
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];

                    if (isValid(newRow, newCol, n) && grid[newRow][newCol]==1)
                    {
                        int nodeVal = row * n + col;
                        int adjNodeval = newRow * n + newCol;

                        if (ds.findPar(nodeVal) != ds.findPar(adjNodeval))
                        {
                            ds.unionBySize(nodeVal, adjNodeval);
                        }
                    }
                }
            }
        }

        int maxSize=-1;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                    continue;

                int dr[] = {-1, +1, 0, 0};
                int dc[] = {0, 0, -1, +1};
                set<int> st;
                for (int i = 0; i < 4; i++)
                {
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];

                    if (isValid(newRow, newCol, n))
                    {
                        int adjNodeval = newRow * n + newCol;

                        if (grid[newRow][newCol] == 1)
                            st.insert(ds.findPar(adjNodeval));
                    }
                }

                // all 4 neighbours are checked
                int Totalsize = 0;  //include the cell in co-ordinate(row,col)
                for (auto it : st)
                {
                    Totalsize += ds.size[it];
                }
                if(Totalsize + 1> maxSize)
                {
                    maxSize=Totalsize +1 ;
                }
            }
        }

        // edge case
        for(int cellNo=0;cellNo< n*n;cellNo++)
        {
            maxSize=max(maxSize,ds.size[ds.findPar(cellNo)]);
        }

        return maxSize;
    }
};

int main()
{

    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1, 0}, {1, 1, 0, 1, 1, 0}, {1, 1, 0, 1, 1, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 0}, {0, 0, 1, 1, 1, 0}};

    Solution obj;
    int ans = obj.MaxConnection(grid);
    cout << "The largest group of connected 1s is of size: " << ans << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/maximum-connected-group/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-connected-group

// https://leetcode.com/problems/making-a-large-island/submissions/1297868002/