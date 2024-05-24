#include <bits/stdc++.h>
using namespace std;
int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        // Handling special case to prevent overflow
        return INT_MAX;
    }
    
    if (dividend == divisor) {
        // Dividend and divisor are equal
        return 1;
    }
    
    bool negative = (dividend > 0) ^ (divisor > 0); // Check if result should be negative

    long long n = abs((long long)dividend); // Convert to long long to avoid overflow
    long long d = abs((long long)divisor);  // Convert to long long to avoid overflow
    
    long long quotient = 0; // Initialize quotient
    
    while (n >= d) {
        long long temp = d;
        long long multiple = 1;
        while (n >= (temp << 1)) {
            temp <<= 1; // Double the divisor
            multiple <<= 1; // Double the multiple
        }
        n -= temp; // Subtract the largest multiple of divisor from dividend
        quotient += multiple; // Update quotient
    }
    
    // Handle quotient greater than 2^31 - 1 or less than -2^31
    if (quotient > INT_MAX) {
        return negative ? INT_MIN : INT_MAX;
    }
    
    return negative ? -quotient : quotient;
}
int main(){
  cout<<divide(22,3);
return 0;
}

// https://leetcode.com/problems/divide-two-integers/