#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    int n=nums.size();
    for(int count=0;count<(1<<n);count++){
        vector<int> temp;
    for(int i=0;i<n;i++){
        if(count&(1<<i)){
            temp.push_back(nums[i]);
        }
    }
    ans.push_back(temp);
    }
    return ans;    
}
int main(){
  
  
  
return 0;
}

// https://leetcode.com/problems/subsets/submissions/