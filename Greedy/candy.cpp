#include <bits/stdc++.h>
using namespace std;
int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> ans(n,1);
        for(int i=1;i<n;i++) // left to right
        {
            if(ratings[i]>ratings[i-1])
            {
                ans[i]=ans[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)  // right to left
        {
            if(ratings[i]>ratings[i+1])
            {
                if(ans[i]<=ans[i+1])
                ans[i]=ans[i+1]+1;
            }
        }
        int sum=0;
        for(auto it:ans)
        sum+=it;

        return sum;
}
int main(){
  
  vector<int> arr={1,0,2};
  cout<<candy(arr);
  
return 0;
}

// https://leetcode.com/problems/candy/submissions/1200606815/