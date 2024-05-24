#include <bits/stdc++.h>
using namespace std;


// You are given a weighted undirected graph having n+1 vertices numbered from 0 to n and m edges describing there are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n, and if the path does not exist then return a list consisting of only -1.
class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Create an adjacency list of pairs of the form node1 -> {node2, edge weight}
        // where the edge weight is the weight of the edge from node1 to node2.
      vector<pair<int,int>> adj[n+1];

      for(auto it: edges)
      {
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
      }

      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n,1e9);
    vector<int> parent(n,-1);
    dist[1]=0;  // 1 is the source and n is the destination
    pq.push({0,1});
      while(!pq.empty())
      {
        int node=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        for(auto it: adj[node])
        {
            int vertex=it.first;
            int wt=it.second;
            if( dis + wt < dist[vertex])  // edge relaxation possible 
            {
                dist[vertex]= dis+ wt;
                pq.push({dist[vertex],vertex});
                parent[vertex]=node;
            }
        }
      }
    
    int destination=n;
    vector<int> res;
    while(parent[destination]!=-1)
    {
        res.push_back(destination);
        destination=parent[destination];
    }

    res.push_back(1);
    reverse(res.begin(),res.end());

    return res;
    }
};

int main()
{
    // Driver Code

    int V = 5, E = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, 
    {3, 5, 1}};
    Solution obj;
    vector<int> path = obj.shortestPath(V, E, edges);

    for (int i = 0; i < path.size(); i++)
    {

        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}