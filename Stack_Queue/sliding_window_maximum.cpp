#include <bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<n;i++)
        {
            // remove out of bound elements
            if(!dq.empty() && dq.front()==i-k)
                dq.pop_front();
            // remove elements less than new element
            while(!dq.empty() && arr[dq.back()]<arr[i])
                dq.pop_back();
            dq.push_back(i);

            // store in answer
            if(i>=k-1)
                ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
int main() {
  int i, j, n, k = 3, x;
  vector < int > arr {4,0,-1,3,5,3,6,8};
  vector < int > ans;
  ans = maxSlidingWindow(arr, k);
  cout << "Maximum element in every " << k << " window " << endl;
  for (i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return 0;
}
// https://leetcode.com/problems/sliding-window-maximum/submissions/1193637975/