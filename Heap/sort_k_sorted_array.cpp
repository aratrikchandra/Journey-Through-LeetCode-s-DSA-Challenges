#include <bits/stdc++.h>
using namespace std;
vector <int> nearlySorted(int arr[], int n, int K){
        vector<int> ans;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<=K;i++){
            pq.push(arr[i]);
        }
        for(int i=K+1;i<n;i++){
            ans.push_back(pq.top());
            pq.pop();
            pq.push(arr[i]);
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
    return ans;
}
int main(){
  int arr[] = {6,5,3,2,8,10,9};
  vector<int> ans=nearlySorted(arr,7,3);
  for(auto it:ans)
  cout<<it<<" ";
return 0;
}

// https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1