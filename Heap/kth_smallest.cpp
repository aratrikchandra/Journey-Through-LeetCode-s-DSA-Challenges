#include <bits/stdc++.h>
using namespace std;
int kthSmallest(int nums[], int l, int r, int k) {
        priority_queue<int> pq;

        for(int i=0;i<k;i++)
        pq.push(nums[i]);

        for(int i=k;i<=r;i++)
        {
            if(nums[i]<pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
    return pq.top();
    }
int main(){
  
  
  
return 0;
}