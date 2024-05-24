#include <bits/stdc++.h>
using namespace std;
int solve(int ind,int sum,int k,int arr[],int n){
    // base case
    if(ind==n)
    {
        if(sum==k){ // valid answer
            return 1;
        }
       else
        return 0;
    }
    int count=0;
    // non pick case
    count+=solve(ind+1,sum,k,arr,n);  
    // pick case
    sum+=arr[ind];
    count+=solve(ind+1,sum,k,arr,n);
    sum-=arr[ind];
    return count;
}
int perfectSum(int arr[], int n, int k)
	{
    int sum=0;
    return solve(0,sum,k,arr,n);
}
int main(){
  
  
  
return 0;
}

// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1