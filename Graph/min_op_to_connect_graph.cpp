#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
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
    int Solve(int n, vector<vector<int>> &edge)
    {
        DisjointSet ds(n);

        int extraEdges = 0;
        for (auto it : edge)
        {
            int u = it[0];
            int v = it[1];
            if (ds.findPar(u) == ds.findPar(v))
            {
                extraEdges++;
            }
            else
            {
                ds.unionBySize(u, v);
            }
        }
        int cmp = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.findPar(i) == i)
                cmp++;
        }
        if (extraEdges >= cmp)
            return cmp - 1;
        else
            return -1;
    }
};

int main()
{

    int V = 9;
    vector<vector<int>> edge = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};

    Solution obj;
    int ans = obj.Solve(V, edge);
    cout << "The number of operations needed: " << ans << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/connecting-the-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=connecting-the-graph