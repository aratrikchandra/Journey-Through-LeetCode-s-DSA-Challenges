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
public:
    int maxRemove(vector<vector<int>> &stones, int n)
    {

        // to approximate the grid size
        int maxRow = -1;
        int maxCol = -1;

        for (auto it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> umap;
        for (auto it : stones)
        {
            int row = it[0];
            int col = it[1];

            int rowVal = row;
            int colVal = col + maxRow+1;

            ds.unionBySize(rowVal, colVal);
            umap[rowVal] = 1; // marking the row and col where stone is present
            umap[colVal] = 1;
        }
        int cmp = 0;
        for (auto it : umap)
        {
            if (it.first == ds.findPar(it.first))
                cmp++;
        }
        return n - cmp;
    }
};

int main()
{

    int n = 6;
    vector<vector<int>> stones = {
        {0, 0}, {0, 2}, {1, 3}, {3, 1}, {3, 2}, {4, 3}};

    Solution obj;
    int ans = obj.maxRemove(stones, n);
    cout << "The maximum number of stones we can remove is: " << ans << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-stone-removal