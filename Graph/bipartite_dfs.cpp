#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, int curr_color, vector<int> &color, vector<int> adj[]){
        color[node]=curr_color;

        for(auto it: adj[node]){
            if(color[it]==-1){
                if(dfs(it,1-curr_color,color,adj)==false)
                return false;
            }
            else if(color[it]!=1-curr_color){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n]; // creating the adjacency list
        for(int i=0;i<n;i++){
            for(auto it: graph[i]){
                adj[i].push_back(it);
            }
        }
        
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1)
            {
                if(dfs(i,0,color,adj)==false)
                return false;
            }
        }
        return true;
    }
};

// https://leetcode.com/problems/is-graph-bipartite/submissions/1292361146/

// https://www.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph