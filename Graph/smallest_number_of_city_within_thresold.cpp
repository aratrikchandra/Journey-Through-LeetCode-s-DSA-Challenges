#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCity(int n, vector<vector<int>> &edges,
                 int Threshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (auto it : edges)
        {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)
                    continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int cntCity=n;
        int cityNo=-1;
        for(int i=0;i<n;i++)
        {
            int neighbours=0;
            for(int j=0;j<n;j++)
            {
                if(dist[i][j]<=Threshold)
                {
                    neighbours++;
                }
            }

            if(neighbours<=cntCity){
                cntCity=neighbours;
                cityNo=i;  // we should have write cityNo=max(cityNo,i) but i is always inc and is greater than any previous city
            }
        }

        return cityNo;
    }
};

int main()
{

    int n = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int distanceThreshold = 4;

    Solution obj;
    int cityNo = obj.findCity(n, edges, distanceThreshold);
    cout << "The answer is node: " << cityNo << endl;

    return 0;
}

// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/