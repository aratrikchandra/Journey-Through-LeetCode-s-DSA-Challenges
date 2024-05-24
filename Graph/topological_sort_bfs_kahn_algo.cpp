#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		vector<int> indegree(V,0);
        vector<int> ans;
        for(int i=0;i<V;i++) // calculating indeg array
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;

        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)  // pushing all nodes with indeg zero in stack
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adj[node])
            {
                indegree[it]--;  // decreasing indeg of adjacent nodes by one
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }

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