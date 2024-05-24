#include <bits/stdc++.h>
using namespace std;
long long sumFirstN(long long n) {
   if(n==0)
   return 0;

   return n+sumFirstN(n-1);
}

// Height of the recrusive tree is O(n), and in the constraints you can see n going up till 10^9, 
// and time limit is 1 sec. If you do know, for 10^8 no. of operations we are taking 1 sec, for an input as big as 10^9 we are exceeding the TLE, that's why the error comes up.
int main(){
  
  
  
return 0;
}