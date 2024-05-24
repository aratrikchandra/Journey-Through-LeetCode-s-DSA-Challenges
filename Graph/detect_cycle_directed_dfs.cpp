#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	bool dfs(int node, vector<int> adj[], vector<int> &visited,vector<int> &pathvisited) {
		visited[node]=1;
        pathvisited[node]=1;

        for(auto it: adj[node])
        {
            if(!visited[it])  // unvisited
            {
                if(dfs(it,adj,visited,pathvisited)==true)
                return true;
            }
            else if(pathvisited[it])
            {
                return true;
            }
        }
        pathvisited[node]=0;

        return false;
	}
public:
	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		vector<int> visited(V,0);
        vector<int> pathvisited(V,0);

        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,adj,visited,pathvisited)==true)
                return true;
            }
        }
        return false;
	}
};


int main() {

	// V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}