#include <bits/stdc++.h>
using namespace std;

int numberOfSubarraysAtMostK(vector<int> &arr, int k){
    int n=arr.size();
    int start=0;
    int end=0;
    int ans=0;
    int count=0;

    for(end=0;end<n;end++)
    {
        if(arr[end]%2==1)
        count++;

        while(start<=end && count>k){
            if(arr[start]%2==1){
                count--;
                start++;
            }
            else{
                start++;
            }
        }

        ans+=end-start+1;
    }
    return ans;
}
int numberOfSubarrays(vector<int> &nums, int k)
{
    return numberOfSubarraysAtMostK(nums,k)-numberOfSubarraysAtMostK(nums,k-1);
}
int main()
{
    vector<int> nums={1, 1, 2, 1, 1};
    int k = 3;
    cout<<numberOfSubarrays(nums,k);
    return 0;
}

// https://leetcode.com/problems/count-number-of-nice-subarrays/submissions/1201548026/