#include <bits/stdc++.h>
using namespace std;
double myPow(double x, int n) {
        double ans=1.0;
        int m=n; // storing the value for sign
        n=abs(n);
        while(n>0){
            if(n&1) // if n is odd
            {
                ans=ans*x;
                n=n-1;
            }
            else{   // if n is even
                n=n/2;
                x=x*x;
            }
        }
        if(m<0){
            ans=1.0/ans;
        }
        return ans;
}
int main(){
  
  
  
return 0;
}

// https://leetcode.com/problems/powx-n/submissions/1211839350/