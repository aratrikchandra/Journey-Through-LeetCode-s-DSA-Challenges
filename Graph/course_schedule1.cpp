#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
bool canFinish(int n, vector<vector<int>>& prerequisites) {
         //code here
        vector<int> adj[n]; // adjacency list
        for(auto it: prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> indegree(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++) // calculating indeg array
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;

        for(int i=0;i<n;i++)
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
        if(ans.size()==n)
        return true;
        else
        return false;
    }
};
int main() {

	int N = 4;
	int M = 3;

	vector<vector<int>> prerequisites(3);
	prerequisites[0].push_back(0);
	prerequisites[0].push_back(1);

	prerequisites[1].push_back(1);
	prerequisites[1].push_back(2);

	prerequisites[2].push_back(2);
	prerequisites[2].push_back(3);

	Solution obj;
	bool ans = obj.canFinish(N, prerequisites);
    cout<<ans;
	return 0;
}

// https://leetcode.com/problems/course-schedule/

