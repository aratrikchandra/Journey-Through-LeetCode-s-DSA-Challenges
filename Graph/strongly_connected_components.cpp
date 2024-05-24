#include <bits/stdc++.h>
using namespace std;

class Solution
{

    private:
    void dfs(int node,vector<int> adj[],vector<int> &visited,stack<int> &st)
    {
        visited[node]=1;

        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                dfs(it,adj,visited,st);
            }
        }
        st.push(node);
    }

public:
    //Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> visited(V,0);
        stack<int> st;

        for(int i=0;i<V;i++)
        {
            if(!visited[i])
             dfs(i,adj,visited,st);
        }
        
        // reverse the edges of the graph
        vector<int> adjRev[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=0;
            for(auto it: adj[i])
            {
                adjRev[it].push_back(i);
            }
        }

        // for simplicity we can create two instances of
        // vector<int> visited1(V,0);
        // another dfs() call
        // but we will try to work with only one

        stack<int> dummy;
        int count=0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            if(!visited[node]){
                dfs(node,adjRev,visited,dummy);
                count++;
            }


        }
    return count;
    }
};

int main() {

    int n = 5;
    int edges[5][2] = {
        {1, 0}, {0, 2},
        {2, 1}, {0, 3},
        {3, 4}
    };
    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    Solution obj;
    int ans = obj.kosaraju(n, adj);
    cout << "The number of strongly connected components is: " << ans << endl;
    return 0;
}