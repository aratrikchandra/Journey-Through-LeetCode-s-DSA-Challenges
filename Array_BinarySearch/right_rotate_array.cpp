#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        int steps=k%n;

        reverse(nums.begin(),nums.begin()+(n-steps));
        reverse(nums.begin()+(n-steps),nums.end());
        reverse(nums.begin(),nums.end());
    }
};

// https://leetcode.com/problems/rotate-array/