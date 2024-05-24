#include <bits/stdc++.h>
using namespace std;
    int countDigits(int num) {
        int n=num;
        int count=0;
        while(n>0){
        int digit=n%10;
        if(num%digit==0)
        count++;
        n=n/10;
    }
    return count;
    }
int main(){
  
  
  
return 0;
}
// https://leetcode.com/problems/count-the-digits-that-divide-a-number/