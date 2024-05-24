#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &ni)
{
    int n = intervals.size();

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        // if curr and new are non-overlapping
        if (intervals[i][1] < ni[0])
        {
            ans.push_back(intervals[i]);
        }
        else if (intervals[i][0] > ni[1])
        {
            ans.push_back(ni);
            for (; i < n; i++)
            {
                ans.push_back(intervals[i]);
            }
            return ans;
        }
        else
        { // they are overlapping
            ni[0] = min(ni[0], intervals[i][0]);
            ni[1] = max(ni[1], intervals[i][1]);
        }
    }
    ans.push_back(ni);
    return ans;
}

int main()
{
    vector<vector<int>> intervals;
    intervals.push_back({1, 3});
    intervals.push_back({6, 9});
    vector<int> newInterval;
    newInterval.push_back(2);
    newInterval.push_back(5);
    intervals = insert(intervals, newInterval);
    for (int i = 0; i < intervals.size(); i++)
    {
        cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]"
             << " ";
    }
    return 0;
}

// https://leetcode.com/problems/insert-interval/submissions/1200575231/