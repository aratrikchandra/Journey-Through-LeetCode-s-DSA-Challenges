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

class Solution {
public:
    int numProvinces(vector<vector<int>> adj, int n) {
      DisjointSet ds(n);
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
            if(i!=j && adj[i][j]==1)
            {
                ds.unionBySize(i,j);
            }
        }
      }
        int cmp=0;
      for(int i=0;i<n;i++)
      {
        if(ds.findPar(i)==i)
            cmp++;
      }

      return cmp;
    }
};

int main() {

    int V = 3;
    vector<vector<int>> adj = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};

    Solution obj;
    int ans = obj.numProvinces(adj, V);
    cout << "The number of provinces is: " << ans << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-provinces