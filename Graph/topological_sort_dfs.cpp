#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
void dfs(int node,vector<int> adj[],vector<int> &visited,stack<int> &st)
{
    visited[node]=1;

    for(auto it: adj[node])
    {
        if(visited[it]==0)
        {
            dfs(it,adj,visited,st);
        }
    }

    st.push(node);
}
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		vector<int> visited(V,0);
        stack<int> st;

        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited,st);
            }
        }

        vector<int> ans;
        while(!st.empty())
        {
            int item=st.top();
            st.pop();
            ans.push_back(item);
        }
        return ans;
	}
};


int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	vector<int> ans = obj.topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}

// https://www.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort