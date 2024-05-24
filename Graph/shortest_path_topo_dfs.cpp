#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    void topo_dfs(int node, vector<pair<int, int>> adj[], vector<int> &visited, stack<int> &st)
    {
        visited[node] = 1;

        for (auto it : adj[node])
        {
            int vertex = it.first;
            int dis = it.second;
            if (!visited[vertex])
            {
                topo_dfs(vertex, adj, visited, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];

        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> visited(N, 0);
        stack<int> st;
        vector<int> dist(N, 1e9);
        dist[0]=0;
        for (int i = 0; i < N; i++){
            if(!visited[i])
            topo_dfs(i, adj, visited, st);
        }
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            for (auto it : adj[node])
            {
                int vertex=it.first;
                int wt = it.second;
                if (dist[node]+wt < dist[vertex])
                {
                    dist[vertex]=dist[node]+wt; // edge relaxation
                    st.push(vertex);
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(dist[i]==1e9)
            dist[i]=-1;
        }
        return dist;
    }
};

int main()
{

    int N = 6, M = 7;

    vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};
    Solution obj;
    vector<int> ans = obj.shortestPath(N, M, edges);

    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << " ";
    }

    return 0;
}

// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1