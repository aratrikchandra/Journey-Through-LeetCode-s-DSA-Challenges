#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> nge(n,-1);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--)
        {
            int item=arr[i%n];

            while(!st.empty() && item>=st.top())
                st.pop();
            
            if(i<n)
            {
                if(!st.empty())
                    nge[i]=st.top();
            }
            st.push(arr[i%n]);
        }
        return nge;
    }
};
int main(){
    Solution obj;
  vector < int > v {5,7,1,2,6,0};
  vector < int > res = obj.nextGreaterElements(v);
  cout << "The next greater elements are" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
return 0;
}

// https://leetcode.com/problems/next-greater-element-ii/submissions/1192504628/