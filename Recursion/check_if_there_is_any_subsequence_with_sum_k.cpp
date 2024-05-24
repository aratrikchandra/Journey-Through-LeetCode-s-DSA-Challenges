#include <bits/stdc++.h>
using namespace std;
bool solve(int ind,int sum,int k,vector<int> &arr,int n){
    // base case
    if(ind==n)
    {
        if(sum==k){ // valid answer
            return true;
        }
       else
        return false;
    }
    // non pick case
    if(solve(ind+1,sum,k,arr,n)==true)
    return true;   
    // pick case
    sum+=arr[ind];
     if(solve(ind+1,sum,k,arr,n)==true)
    return true; 
    sum-=arr[ind];
    return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
       int sum=0;
    return solve(0,sum,k,a,n);
}
// https://www.naukri.com/code360/problems/subset-sum_630213?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION
int main(){
  
  
  
return 0;
}