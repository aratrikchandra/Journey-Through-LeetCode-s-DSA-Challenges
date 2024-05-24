#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
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
    bool isValid(int row, int col, int n, int m)
    {
        return row >= 0 && row < n && col >= 0 && col < m;
    }

public:
    vector<int> numOfIslands(int n, int m,
                             vector<vector<int>> &operators)
    {

        DisjointSet ds(n * m);
        int visited[n][m];
        memset(visited, 0, sizeof visited); // to set all zeroes

        int cmp = 0;
        vector<int> ans;
        for (auto it : operators)
        {
            int row = it[0];
            int col = it[1];

            if (visited[row][col] == 1)  // this query is already seen before
            {
                ans.push_back(cmp);
                continue;
            }

            visited[row][col]=1;  // not queried before
            cmp++;

            int dr[] = {-1, +1, 0, 0};
            int dc[] = {0, 0, -1, +1};

            for (int i = 0; i < 4; i++)
            {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (isValid(newRow, newCol, n, m))
                {
                    if (visited[newRow][newCol] == 1)
                    {
                        int nodeVal = row * m + col;
                        int adjNodeval = newRow * m + newCol;

                        if (ds.findPar(nodeVal) != ds.findPar(adjNodeval))
                        {
                            ds.unionBySize(nodeVal, adjNodeval);
                            cmp--;
                        }
                    }
                }
            }

            ans.push_back(cmp);
        }

        return ans;
    }
};

int main()
{

    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1}, {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}};

    Solution obj;
    vector<int> ans = obj.numOfIslands(n, m, operators);
    for (auto res : ans)
    {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands