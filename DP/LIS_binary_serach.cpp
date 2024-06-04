#include <bits/stdc++.h>
using namespace std;
int longestSubsequence(int n, int arr[])
    {
        //edge case
        if(n==0)
        return 0;
       vector<int> temp;
       temp.push_back(arr[0]);
        int len=1;
       for(int i=1;i<n;i++){
        if(arr[i]>temp.back()){ // maintaining the inc order
            temp.push_back(arr[i]);
            len++;
        }
        else{
            int ind=lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            temp[ind]=arr[i];
        }
       }
       return len;
    }
// https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-increasing-subsequence
int main(){
  
  
  
return 0;
}