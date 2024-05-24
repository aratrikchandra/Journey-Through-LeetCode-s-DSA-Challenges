#include <bits/stdc++.h>
using namespace std;
vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        long xor_value = 0;
        for(int i=0;i<nums.size();i++){
            xor_value=xor_value^nums[i];
        }
        int diffBit=(xor_value&(xor_value-1))^xor_value;
        int setBucket=0;
        int unsetBucket=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&diffBit)
            setBucket=setBucket^nums[i];
            else
            unsetBucket=unsetBucket^nums[i];
        }
        ans.push_back(setBucket);
        ans.push_back(unsetBucket);
        return ans;
}
int main(){
  
  
  
return 0;
}

// https://leetcode.com/problems/single-number-iii/submissions/1210263335/