#include <bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
                st.push(arr[i]);
            else{ // arr[i] is neg
                while(!st.empty() && st.top()>0 && st.top()<-arr[i])
                    st.pop();
                if(st.empty() || st.top()<0)
                    st.push(arr[i]);
                else if(st.top()>0 && st.top()>-arr[i])
                    {
                        // destroy arr[i]
                    }
                    else if(st.top()==-arr[i])
                    {
                        st.pop(); // destroy arr[i] and st.top()
                    }
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
int main(){
  vector<int> arr={5,10,-5};
  vector<int> ans=asteroidCollision(arr);
  for(auto it:ans)
  {
    cout<<it<<" ";
  }
return 0;
}

// https://leetcode.com/problems/asteroid-collision/submissions/1194656232/