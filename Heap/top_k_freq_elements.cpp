#include <bits/stdc++.h>
using namespace std;
vector<int> topKFrequent(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> umap;
        for(int i=0;i<n;i++) // freq count
        umap[arr[i]]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it:umap){
            pq.push({it.second,it.first});
            if(pq.size()>k)
            pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
int main(){
  
  vector<int> arr={1,1,1,2,2,3};
  int k=2;
    vector<int> ans=topKFrequent(arr,k);
  for(auto it:ans)
  cout<<it<<" ";
  
return 0;
}