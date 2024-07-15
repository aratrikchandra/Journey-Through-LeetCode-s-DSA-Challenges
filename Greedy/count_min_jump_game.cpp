#include <bits/stdc++.h>
using namespace std;
int jump(vector<int>& nums) {
        int n=nums.size();
        //edge case
        if(n==1)
        return 0;
        int maxIndex=0;
        int l=0;
        int r=0;
        int jumps=0;
        while(r<n){
            for(int i=l;i<=r;i++){
                maxIndex=max(maxIndex,i+nums[i]);
            }
            l=r+1;
            r=maxIndex;
            jumps++;
            if(maxIndex>=n-1)
            return jumps;
        }
        return jumps;
    }
int main()
{

    vector<int> arr = {2, 3, 1, 1, 4};
    cout << jump(arr);

    return 0;
}

// https://leetcode.com/problems/jump-game-ii/submissions/1197672506/