#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    // dfs traversal function 
    void dfs(int node, vector<int> adjLs[], int vis[]) {
        // mark the more as visited
        vis[node] = 1; 
        for(auto it: adjLs[node]) {
            if(!vis[it]) {
                dfs(it, adjLs, vis); 
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {

    vector<int> adjList[V];

      for(int i=0;i<V;i++)
      {
        for(int j=0;j<V;j++)
        {
            if(adj[i][j]==1 && i!=j)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
      }

      int visited[V]={0};
      int cmp=0;
      for(int i=0;i<V;i++)
      {
        if(!visited[i])
        {
            cmp++;
            dfs(i,adjList,visited);
        }
      } 
      return cmp;  
    }
};

int main() {
    
    vector<vector<int>> adj
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

        
    Solution ob;
    cout << ob.numProvinces(adj,3) << endl;
        
    return 0;
}

// https://www.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces