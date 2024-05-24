class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int n=nums.size();
        int j;
        for(j=0;j<n;j++)
        {
            if(nums[j]==0)
                break;
        }
        if(j==n)
         return;

         int i=j+1;
         while(i<n)
         {
             if(nums[i]!=0)
             {
                 swap(nums[i],nums[j]);
                 j++;
             }
             i++;
         }

    }
};

// https://leetcode.com/problems/move-zeroes/submissions/1158358641/