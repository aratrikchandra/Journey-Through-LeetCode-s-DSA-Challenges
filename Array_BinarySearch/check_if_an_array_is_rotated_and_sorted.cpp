#include <bits/stdc++.h>
using namespace std;
bool check(vector<int>& nums) {
        int n=nums.size();
        int pivot=0;

        for(int i=1;i<n;i++){ // check for rotated array
            if(nums[i-1]>nums[i])
            pivot++;
        }

        if(nums[n-1]>nums[0]) // check for sorted array
        pivot++;

        return (pivot<=1);
    }
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/submissions/1288223893/
int main(){
  
  
  
return 0;
}