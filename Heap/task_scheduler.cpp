#include <bits/stdc++.h>
using namespace std;
int leastInterval(vector<char> &tasks, int n)
{
    unordered_map<char, int> mp;
    for (auto it : tasks) // storing freq count in map
        mp[it]++;

    priority_queue<pair<int, int>> pq; // elements look like <freq,possible start time of execution> but all the items are runnable
    for (auto it : mp)
    {
        pq.push({it.second, 0}); // all the tasks have possible start time zero initially
    }
    queue<pair<int, int>> q; // elements look like <freq,possible start time of execution> but all the items are non-runnable i.e they have to wait
    int time = 0;
    while (!pq.empty() || !q.empty())
    {
        // check if we have some job in queue whose cooling time is over
        if (!q.empty() && time - q.front().second > n)
        {
            auto task = q.front();
            q.pop();
            pq.push(task);
        }
        if (!pq.empty())
        {
            auto task = pq.top();
            pq.pop();
            int freq = task.first;
            int t = task.second;
            if (freq > 1)
            {
                q.push({freq - 1, time});
            }
        }
        time++;
    }
    return time;
}
int main()
{
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int k = 2;
    cout << leastInterval(tasks, k);
    return 0;
}

// https://leetcode.com/problems/task-scheduler/submissions/1207360109/