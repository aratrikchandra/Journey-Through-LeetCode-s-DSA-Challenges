#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int S) {
        
        vector<pair<int,int>> adj[n+1];  // adj list rep
        for(auto it: times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        pq.push({0,S});
        dist[S]=0;
        while(!pq.empty())
        {
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();

            for(auto it: adj[node])
            {
                int wt=it.second;
                int vertex=it.first;
                if(dis + wt < dist[vertex])
                {
                    dist[vertex]=dis+wt;
                    pq.push({dist[vertex],vertex});
                }
            }
        }
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==1e9)
            {
                return -1;
            }
            mx=max(mx,dist[i]);              
        }
        return mx;
    }
};

// https://leetcode.com/problems/network-delay-time/submissions/1157366504/