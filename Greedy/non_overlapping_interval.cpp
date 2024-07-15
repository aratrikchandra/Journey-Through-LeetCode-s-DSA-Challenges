#include <bits/stdc++.h>
using namespace std;

class Meeting{
    public:
  int start;
  int end;
  int id;
  
  Meeting(){
      start=0;
      end=0;
      id=0;
  }
  Meeting(int start, int end, int id){
      this->start=start;
      this->end=end;
      this->id=id;
  }
  
};
class Solution
{
    public:
    static bool comp(Meeting m1, Meeting m2){
        return m1.end<m2.end;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(vector<vector<int>>& intervals, int n)
    {
        Meeting arr[n];
        for(int i=0;i<n;i++){
            Meeting m=Meeting(intervals[i][0],intervals[i][1],i+1);
            arr[i]=m;
        }
        sort(arr,arr+n,comp);
        int count=1;
        int finishTime=arr[0].end;
        for(int i=1;i<n;i++){
            if(arr[i].start>=finishTime){
                count++;
                finishTime=arr[i].end;
            }
        }
        return count;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        return n-maxMeetings(intervals,n);
    }
};


// https://leetcode.com/problems/non-overlapping-intervals/submissions/1319961497/