#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty() || st.top()<0){
                st.push(arr[i]);
                continue;
            }

            if(arr[i]>0){
                st.push(arr[i]);
            }
            else{
                while(!st.empty() && st.top()>0 && abs(arr[i])>st.top()){
                    st.pop();
                }
                if(st.empty() || st.top()<0)
                st.push(arr[i]);
                else if(abs(arr[i]<st.top())){
                    continue;
                }
                else{
                    st.pop();
                }
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
int main(){
  
  vector<int> arr={50,5,10,20,-5,-30,40};
  vector<int> ans=asteroidCollision(arr);
for(auto it: ans){
    cout<<it<<" ";
}
return 0;
}