#include <bits/stdc++.h>
using namespace std;

// Brute Force
int countSetBitsOfN(int n){
        int count = 0;

    while (n > 0)
    {
        if (n & 1) // if n is odd
            count++;

        n = n >> 1; // divide by two
    }
    return count;
}

int countSetBits(int n)
{
    int count=0;
    for(int i=1;i<=n;i++){
        count+=countSetBitsOfN(i);
    }
    return count;
}

// Optimal
vector<int> countBits(int n) {
       vector<int> ans(n+1,0); // initially all elements have zero set bits and ans[0]=0 is the base case

       for(int i=1;i<=n;i++){
            ans[i]=ans[i/2]+(i%2);
       } 
       return ans;
}

// https://leetcode.com/problems/counting-bits/submissions/1212646654/
int main(){
  
  
  
return 0;
}