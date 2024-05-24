#include <bits/stdc++.h>
using namespace std;
long long minCost(long long arr[], long long n) {
        
        priority_queue<long long,vector<long long>,greater<long long>> pq;

        for(int i=0;i<n;i++)
        pq.push(arr[i]);
        long long ans=0;
        while(pq.size()>1){
            int cost1=pq.top();
            pq.pop();
            int cost2=pq.top();
            pq.pop();
            int cost=cost1+cost2;
            ans+=cost;
            pq.push(cost);
        }
        return ans;
    }
int main(){
  
  
  
return 0;
}
// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1