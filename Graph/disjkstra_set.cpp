#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>> st;
        vector<int> dist(V,1e9);
        st.insert({0,S});
        dist[S]=0;
        while(!st.empty())
        {
            auto it=*(st.begin());
            int node=it.second;
            int dis=it.first;
            st.erase({dis,node});

            for(auto it: adj[node])
            {
                int wt=it[1];
                int vertex=it[0];
                if(dis + wt < dist[vertex])  // edge relaxation possible
                {
                    if(dist[vertex]!=1e9)  // previously present in set with higher distance
                    {
                        st.erase({dist[vertex],vertex});
                    }
                    dist[vertex]=dis+wt;
                    st.insert({dist[vertex],vertex});
                }
            }
        }

        return dist;
    }
};

int main()
{
    // Driver code.
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/0