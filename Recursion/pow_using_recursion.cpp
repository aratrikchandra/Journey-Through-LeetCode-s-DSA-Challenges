#include <bits/stdc++.h>
using namespace std;
 double solve(double x,long n){
        if(n<0)
        return solve(1/x,-n);
         // base case
        if(n==0)
        return 1;
        double temp=solve(x,n/2);
        if(n%2==0){
            return temp*temp;
        }
        else
            return x*temp*temp;
    }
    double myPow(double x, int n) {
       return solve(x,n);
    }
// https://leetcode.com/problems/powx-n/
int main(){
  
  
  
return 0;
}