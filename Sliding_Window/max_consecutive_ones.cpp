#include <bits/stdc++.h>
using namespace std;
int longestOnes(vector<int>& nums, int k) {
    int n=nums.size();
        int count=0;
        int maxCount=0;
        queue<int> q;

        for(int i=0;i<n;i++){

            if(nums[i]==0){
                if(k>0){
                    count++;
                    k--;
                    q.push(i);
                }
                else{
                    if(!q.empty()){
                        int ind=q.front();
                        q.pop();
                        count=i-ind;
                        q.push(i);
                    }
                    else
                    count=0;
                }
            }else{
                count++;
            }
            maxCount=max(count,maxCount);
        }
        return maxCount;
    }
int main(){
  
  vector<int> nums= {1,1,1,0,0,0,1,1,1,1,0};
  int k = 2;
  cout<<longestOnes(nums,k);
return 0;
}

// https://leetcode.com/problems/max-consecutive-ones-iii/submissions/1201584503/