#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights,
                       int src, int dst, int K)
    {
        vector<pair<int,int>> adj[n];

        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        dist[src]=0;
        q.push({0,{src,0}});

        while(!q.empty())
        {
            int stops=q.front().first;
            int node=q.front().second.first;
            int dis=q.front().second.second;
            q.pop();

            if(stops > K)
                continue;
            
            for(auto it: adj[node])
            {
                int vertex=it.first;
                int wt=it.second;
                if(dis + wt < dist[vertex] && stops<=K)
                {
                    dist[vertex]=dis+ wt;
                    q.push({stops+1,{vertex,dist[vertex]}});
                }
            }
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};

int main()
{
    // Driver Code.
    int n = 4, src = 0, dst = 3, K = 1;

    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600},
    {2, 3, 200}};

    Solution obj;

    int ans = obj.CheapestFLight(n, flights, src, dst, K);

    cout << ans;
    cout << endl;

    return 0;
}

// https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/1150943708/