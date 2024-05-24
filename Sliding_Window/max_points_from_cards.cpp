#include <bits/stdc++.h>
using namespace std;
int maxScore(vector<int>& cards, int k) {
        int n=cards.size();
        int start=k;
        int end=n-1;
        int sum=0;
        int maxSum=INT_MIN;
        for(int i=0;i<k;i++)
        sum+=cards[i];

        if(k==n)
        return sum;
        maxSum=max(maxSum,sum); // if first time included elements give the answer
        while(start>0){
          start--;
          sum=sum-cards[start];
          sum=sum+cards[end];
          end--;
          maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
int main(){
  
  vector<int> vec={1,2,3,4,5,6,1};
  int k=3;
  cout<<maxScore(vec,k);
  
return 0;
}

// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/submissions/1203600974/