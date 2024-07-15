#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int V, vector<vector<int>> adj[])
	{
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int> visited(V,0);
        pq.push({0,0});
        int sum=0;
        while(!pq.empty())
        {
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();

            if(visited[node]==1)
                continue;
            
            visited[node]=1;
            sum+=wt;   // include in MST

            for(auto it:adj[node])
            {
                int vertex=it[0];
                int edgeWt=it[1];

                if(!visited[vertex])
                    pq.push({edgeWt,vertex});
            }
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
	int sum = obj.spanningTree(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

	return 0;
}

// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree

// using Dijkstra's Algorithm
int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<int> dist(n,1e9);
        vector<int> prev(n,-1);
        vector<int> visited(n,0);
        dist[0]=0;
        
        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            if(visited[node]==1)
            continue;
            // int dis=it.first;
             visited[node]=1;
            
            for(auto it: adj[node]){
                int v=it[0];
                int wt=it[1];
                
                if(visited[v]==0 && wt<dist[v])
                {
                    dist[v]=wt;
                    prev[v]=node;
                    pq.push({wt,v});
                }
            }
        }
        for (int i = 1; i < n; i++) {
        sum += dist[i]; // Sum of MST edge weights
        }
        return sum;
    }