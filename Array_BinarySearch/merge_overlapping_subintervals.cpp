


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
   int n=arr.size();
vector<vector<int>> ans;
   sort(arr.begin(),arr.end());
   for(int i=0;i<n;i++)
   {
    if(ans.size()==0 || arr[i][0] > ans.back()[1]) // when merging is not possible
        ans.push_back(arr[i]);
    else{
        ans.back()[1]=max(ans.back()[1],arr[i][1]);  // when merging is possible
    }
   }
   return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/merge-intervals/submissions/1169933520/