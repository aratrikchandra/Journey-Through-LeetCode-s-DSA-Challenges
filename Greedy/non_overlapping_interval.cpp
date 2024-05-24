#include <bits/stdc++.h>
using namespace std;

bool static comp(vector<int> &arr1, vector<int> &arr2)
{
    return arr1[1] < arr2[1];
}
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), comp);
    int count = 0;
    int end=intervals[0][1];
    for(int i=1;i<n;i++)
    {
        if(end>intervals[i][0])
        {
            count++;
        }
        else{
            end=intervals[i][1];
        }
    }
    return count;
}
int main()
{

    return 0;
}

// https://leetcode.com/problems/non-overlapping-intervals/submissions/1200601059/