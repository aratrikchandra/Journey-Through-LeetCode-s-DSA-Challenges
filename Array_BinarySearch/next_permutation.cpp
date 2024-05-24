
#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ind=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1]) // break point exists
            {
                ind=i;
                break;
            }
        }

        if(ind==-1) // break point does not exist i.e. we are in last permutation
        {
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1;i>=ind;i--)
        {
            if(nums[i]>nums[ind])
            {
                swap(nums[i],nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1,nums.end());
    }

int main()
{
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
     nextPermutation(A);

    cout << "The next permutation is: [";
    for (auto it : A) {
        cout << it << " ";
    }
    cout << "]\n";
    return 0;
}

// https://leetcode.com/problems/next-permutation/submissions/1166103280/