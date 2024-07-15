#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 

   // using bfs
    bool bfs(int v, vector<int> adj[],vector<int> &visited, queue<pair<int,int>> &q){

       q.push({v,-1});
       visited[v]=1;
       while(!q.empty()){
           auto it=q.front();
           q.pop();
           int node=it.first;
           int parent=it.second;
           
           for(auto it: adj[node]){
               if(visited[it]==0){
                   q.push({it,node});
                   visited[it]=1;
               }
               else if(it!=parent){
                   return true;
               }
           }
       }
       return false;
    }
    public:
    bool isCycle(int n, vector<int> adj[]) {
        vector<int> visited(n,0);
       queue<pair<int,int>> q;
       for(int i=0;i<n;i++){
           if(visited[i]==0){
               if(bfs(i,adj,visited,q)==true)
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