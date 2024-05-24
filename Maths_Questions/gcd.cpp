#include <bits/stdc++.h>
using namespace std;

// Eucledian Algorithm
int calcGCD(int n, int m){
   if(n%m==0)
   return m;
   if(m%n==0)
   return n;

   while(n>0 && m>0){
    if(n>m)
    n=n%m;
    else
    m=m%n;
   }
   if(m==0) return n;
   if(n==0) return m;
}
int main(){
  
  
  
return 0;
}

// https://www.codingninjas.com/studio/problems/hcf-and-lcm_840448?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION