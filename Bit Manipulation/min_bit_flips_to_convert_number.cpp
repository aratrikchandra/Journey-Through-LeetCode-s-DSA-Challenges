#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int countSetBytes(int n)
{
    int count = 0;

    while (n > 0)
    {
        if (n & 1) // if n is odd
            count++;

        n = n >> 1; // divide by two
    }
    return count;
}
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        return countSetBytes(ans);
    }
};
int main(){
  
  
  
return 0;
}

// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/submissions/1210000809/