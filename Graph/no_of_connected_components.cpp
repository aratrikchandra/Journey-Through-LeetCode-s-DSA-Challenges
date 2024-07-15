#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int node, vector<int>& visited,
             vector<int> adj[]) {
        visited[node] = 1;
        // ans.push_back(node);

        for (auto it : adj[node]) {
            if (visited[it] == 0)
                dfs(it, visited, adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // converting adj matrix to adj list
        vector<int> adj[n + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1)
                    adj[i + 1].push_back(j + 1);
            }
        }

        vector<int> visited(n+1,0);
        int count=0;
        for(int i=1;i<=n;i++){
            if(visited[i]==0)
            {
                dfs(i,visited,adj);
                count++;
            }
        }
        return count;
    }
};
// https://leetcode.com/problems/number-of-provinces/submissions/1290133166/


// https://www.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces