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
        int u_par=findPar(u);
        int v_par=findPar(v);
        // check if they are in same component or not
        if (u_par==v_par)
            return;
        int u_rank = rank[u_par];
        int v_rank = rank[v_par];

        if (u_rank < v_rank)
        {
            parent[u_par] = v_par;
        }
        else if(v_rank<u_rank)
        {
            parent[v_par] = u_par;
        }
        else{
            parent[v_par] = u_par;
            rank[u_par]+=1;
        }
    }

    void unionBySize(int u, int v)
    {
        int u_par=findPar(u);
        int v_par=findPar(v);
        // check if they are in same component or not
        if (u_par==v_par)
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
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;

        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                int adjNode=it[0];
                int node =i;
                int wt=it[1];

                edges.push_back({wt,{node,adjNode}});
            }
        }

        sort(edges.begin(),edges.end());
        DisjointSet ds(V);
        int sum=0;
        for(auto it: edges)
        {
            int u=it.second.first;
            int v=it.second.second;
            int wt=it.first;

            if(ds.findPar(u)==ds.findPar(v))
            {
                continue;
            }
            sum+=wt;

            ds.unionBySize(u,v);

        }
        return sum;
    }
};

int main() {

    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    Solution obj;
    int mstWt = obj.spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << mstWt << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree