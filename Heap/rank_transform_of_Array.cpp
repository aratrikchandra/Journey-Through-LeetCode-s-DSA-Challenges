#include <bits/stdc++.h>
using namespace std;
vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> dummy(arr);

        sort(dummy.begin(),dummy.end());
        int rank=1;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(dummy[i])==mp.end())  // if the element not present before
            {
                mp[dummy[i]]=rank;
                rank++;
            }
        }
        for(int i=0;i<n;i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
}
int main(){
  
  vector<int> arr={40,10,20,30};
    vector<int> ans=arrayRankTransform(arr);
   for(auto it:ans)
  cout<<it<<" ";
  
return 0;
}