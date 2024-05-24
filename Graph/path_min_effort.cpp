#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MinimumEffort(vector<vector<int>> &heights)
    {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> diff(n,vector<int> (m,1e9));

        pq.push({0,{0,0}});
        diff[0][0]=0;
        int dr[]={-1,+1,0,0};
        int dc[]={0,0,-1,1};
        while(!pq.empty())
        {
            int difference=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            if(row==n-1 && col==m-1)
            {
                return difference;
            }

            for(int i=0;i<4;i++)
            {
                int nRow=row+dr[i];
                int nCol=col+dc[i];

                if(nRow>=0 && nCol>=0 && nRow<n && nCol<m)
                {
                    int newEffort=max(abs(heights[row][col]-heights[nRow][nCol]),difference);

                    if(newEffort < diff[nRow][nCol])
                    {
                        diff[nRow][nCol]=newEffort;
                        pq.push({newEffort,{nRow,nCol}});
                    }
                }
            }
        }

        return 0; // dest not reachable
    }
};

int main()
{
    // Driver Code.

    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    Solution obj;

    int ans = obj.MinimumEffort(heights);

    cout << ans;
    cout << endl;

    return 0;
}

// https://leetcode.com/problems/path-with-minimum-effort/submissions/1150920451/