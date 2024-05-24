#include <bits/stdc++.h>
using namespace std;

int numSubarraysSumAtmostK(vector<int> arr,int k){
    int n=arr.size();
    int start=0;
    int sum=0;
    int count=0;
    int end=0;
    for(end=0;end<n;end++)
    {
        sum+=arr[end];        
        while(start<=end && sum>k){  // if sum exceeds k
            sum=sum-arr[start];
            start++;
        }
        count+=end-start+1;
    }
    return count;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysSumAtmostK(nums,goal) -numSubarraysSumAtmostK(nums,goal-1); 
}
int main(){
  
  vector<int> nums = {1,0,1,0,1};
  int goal = 2;
  cout<<numSubarraysWithSum(nums,goal);
return 0;
}

// https://leetcode.com/problems/binary-subarrays-with-sum/submissions/1201539569/