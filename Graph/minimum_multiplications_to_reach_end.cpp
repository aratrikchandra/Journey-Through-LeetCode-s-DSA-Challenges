#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr,
                               int start, int end)
    {
        // imp edge case
        if (start == end)
            return 0;

            
        int mod = 1e5;

        queue<pair<int, int>> q;
        vector<int> dist(mod, 1e9);
        q.push({0, start});
        dist[start] = 0;

        while (!q.empty())
        {
            int dis = q.front().first;
            int node = q.front().second;
            q.pop();
            for (int i = 0; i < arr.size(); i++)
            {
                int vertex = (node * arr[i]) % mod;
                if (dis + 1 < dist[vertex])
                {
                    dist[vertex] = dis + 1;
                    if (vertex == end)
                    {
                        return dis + 1;
                    }
                    q.push({dis + 1, vertex});
                }
            }
        }
        return -1;
    }
};

int main()
{
    // Driver Code.
    int start = 3, end = 30;

    vector<int> arr = {2, 5, 7};

    Solution obj;

    int ans = obj.minimumMultiplications(arr, start, end);

    cout << ans;
    cout << endl;

    return 0;
}

// https: // www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-multiplications-to-reach-end