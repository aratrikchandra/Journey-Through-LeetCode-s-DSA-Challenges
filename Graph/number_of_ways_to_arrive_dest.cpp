#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        int mod=1e9+7;
        vector<pair<long long,long long>> adj[n];

        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;

        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n,0);

        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;

        while(!pq.empty())
        {
            long long dis=pq.top().first;
            long long node=pq.top().second;

            pq.pop();

            for(auto it: adj[node])
            {
                long long vertex=it.first;
                long long wt=it.second;

                if(dis + wt < dist[vertex])
                {
                    dist[vertex]=dis+wt;
                    ways[vertex]=ways[node]%mod;
                    pq.push({dist[vertex],vertex});
                }
                else if(dis +wt ==dist[vertex])
                {
                    ways[vertex]+=ways[node]%mod;
                }
            }
        }
        return ways[n-1]%mod;


    }
};

int main()
{
    // Driver Code.
    int n = 7;

    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, 
    {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    Solution obj;

    int ans = obj.countPaths(n, edges);

    cout << ans;
    cout << endl;

    return 0;
}