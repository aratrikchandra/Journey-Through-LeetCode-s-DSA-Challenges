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
int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findPar(3) == ds.findPar(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findPar(3) == ds.findPar(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";
    return 0;
}