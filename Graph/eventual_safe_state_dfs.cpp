#include <bits/stdc++.h>
using namespace std;


class Solution {
private:

bool dfs(int node,vector<int> adj[],vector<int> &visited,vector<int> &pathvisited,vector<int> &check)
{
    visited[node]=1;
    pathvisited[node]=1;

    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            if(dfs(it,adj,visited,pathvisited,check)==true)  // this node leads to a cycle
            {
                check[it]=0;
                return true;
            }
        }
        else if(pathvisited[it]==1) // this node is part of cycle
        {
            check[it]=0;
            return true;
        }
    }

    pathvisited[node]=0;
    check[node]=1;
    return false;
}
public:
	vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
		vector<int> visited(V,0);
        vector<int> pathvisited(V,0);
        vector<int> check(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited,pathvisited,check);
            }
        }
        vector<int> safeNodes;
        for(int i=0;i<V;i++)
        {
            if(check[i])
            safeNodes.push_back(i);
        }

        return safeNodes;
	}
};


int main() {

	//V = 12;
	vector<int> adj[12] = {{1}, {2}, {3}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10}, 
        {8},{9}};
	int V = 12;
	Solution obj;
	vector<int> safeNodes = obj.eventualSafeNodes(V, adj);

	for (auto node : safeNodes) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}

// https://www.geeksforgeeks.org/problems/eventual-safe-states/1