#include <bits/stdc++.h>
using namespace std;
class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int>> pq;  // min heap
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        int n=nums.size();
        for(int i=0;i<min(k,n);i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<n;i++){
            if(nums[i]>pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<k)
        pq.push(val);
        else if(val>pq.top())
            {
                pq.pop();
                pq.push(val);
            }
            return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
int main(){
  
  
  
return 0;
}

// https://leetcode.com/problems/kth-largest-element-in-a-stream/