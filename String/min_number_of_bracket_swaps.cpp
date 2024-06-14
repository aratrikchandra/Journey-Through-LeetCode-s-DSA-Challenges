#include <bits/stdc++.h>
using namespace std;
int minSwaps(string s) {
        int n=s.size();
        int extraClose=0;
        int maxClose=0;
        for(int i=0;i<n;i++){
            if(s[i]=='[')
            extraClose--;
            else
            extraClose++;

            maxClose=max(maxClose,extraClose);
        }
        if(maxClose&1) // if maxClose is odd
        return (maxClose+1)/2;
        else
        return maxClose/2;
    }
// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/submissions/1284144142/
int main(){
  
  
  
return 0;
}