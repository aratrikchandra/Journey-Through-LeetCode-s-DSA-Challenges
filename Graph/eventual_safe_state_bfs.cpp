#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
		// to reverse the edges of the graph
        vector<int> adjRev[V];
        vector<int> indegeree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i]) // for edges i->it we will reverse and set it->i
            {
                adjRev[it].push_back(i);
                indegeree[i]++;
            }
        }
        queue<int> q;
        vector<int> topo;
        for(int i=0;i<V;i++)
        {
            if(indegeree[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adjRev[node])
            {
                indegeree[it]--;
                if(indegeree[it]==0)
                {
                    q.push(it);
                }
            }
        }

        sort(topo.begin(),topo.end());

        return topo;
	}
};

int main() {

	vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
		{8}, {9}
	};
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