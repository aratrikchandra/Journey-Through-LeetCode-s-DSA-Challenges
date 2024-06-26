#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=i+1;
        while(j<n)
        {
            if(nums[j]!=nums[i])
            {
                nums[i+1]=nums[j];
                i++;
            }
            j++;
        }
        return i+1;
    }
};

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/