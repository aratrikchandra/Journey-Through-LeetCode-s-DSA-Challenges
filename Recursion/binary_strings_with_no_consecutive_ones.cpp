#include <bits/stdc++.h>
using namespace std;
long long solve(int i,int n){
	   // base case
       if(i==n-1)
       return 2;

       return solve(i+1,n)+solve(i+2,n);
}
long long countStrings(int n) {
       return 0; 
}
int main(){
  
  
  
return 0;
}