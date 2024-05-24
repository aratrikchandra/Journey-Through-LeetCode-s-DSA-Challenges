#include <bits/stdc++.h>
using namespace std;
int jump(vector<int>& arr) {
        int n = arr.size();
    if(n==1)
    return 0;
    int coverage = 0;
    int lastIndexOfCurrentWindow=0;
    int jumps=0;
    for(int i=0;i<n;i++)
    {
        coverage=max(coverage,i+arr[i]);
         if(coverage>=n-1)
        {
            jumps++;
            return jumps;
        } 
        if(i==lastIndexOfCurrentWindow)
        {
            lastIndexOfCurrentWindow=coverage;
            jumps++; // increment jump count when we completed a window and jumping to new one
        }  
    }
    return jumps;
    }
int main()
{

    vector<int> arr = {2, 3, 1, 1, 4};
    cout << jump(arr);

    return 0;
}

// https://leetcode.com/problems/jump-game-ii/submissions/1197672506/