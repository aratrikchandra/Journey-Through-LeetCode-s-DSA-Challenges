#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 

    bool bfs(int node,int visited[],vector<int> adj[])
    {
        visited[node]=1;
        queue<pair<int,int>> q;  // <node,parent>

        q.push({node,-1}); // pushing the starting node

        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;

            q.pop();

            for(auto it: adj[node])
            {
                if(!visited[it])  // if adjacent node is unvisited
                {
                    q.push({it,node});
                    visited[it]=1;
                }
                else if(it != parent) // if adjacent node is visited and also not parent
                {
                    return true;
                }
            }
        }

    return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int visited[V]={0};

        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(bfs(i,visited,adj)==true)  // call for different connnected component
                return true;  
            }
        }

        return false;
    }
};

int main() {
    
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}

// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph