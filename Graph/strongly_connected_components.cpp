#include <bits/stdc++.h>
using namespace std;

	#include<bits/stdc++.h>
	void dfsRev(int node, vector<int> &visited,vector<int> adj[]){
	    visited[node]=1;
	    
	    for(auto it: adj[node]){
	        if(visited[it]==0)
	        dfsRev(it,visited,adj);
	    }
	}
	void dfs(int node, vector<int> &visited,stack<int> &st,vector<int> adj[]){
	    visited[node]=1;
	    
	    for(auto it: adj[node]){
	        if(visited[it]==0)
	        dfs(it,visited,st,adj);
	    }
	    st.push(node);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<vector<int>>& graph)
    {
        vector<int> adj[n];
        for(auto it: graph){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> visited(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(visited[i]==0)
            dfs(i,visited,st,adj);
        }
        // constructing the reverse graph
        vector<int> adjRev[n];
        for(int i=0;i<n;i++){
            for(auto it: adj[i]){
                adjRev[it].push_back(i);
            }
        }
        for(int i=0;i<n;i++){
            visited[i]=0;
        }
        int count=0;
        while(!st.empty()){
            int node=st.top();
            if(visited[node]==0)
            {
                dfsRev(node,visited,adjRev);
                count++;
            }
            st.pop();
        }
        return count;
    }
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	return kosaraju(v,edges);
}

// https://www.naukri.com/code360/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTabValue=SUBMISSION