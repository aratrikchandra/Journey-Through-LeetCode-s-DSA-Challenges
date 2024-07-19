#include <iostream>
#include <bits/stdc++.h>
using namespace std;

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> ans;
        int i=0;
        // non-overlapping part(left)
        while(i<n && intervals[i][1]<newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        // overlapping part
        while(i<n && newInterval[1]>=intervals[i][0]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        // non-overlapping part(right)
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }

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