#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int x)
{
     if (x <= 1) // important edge case
     return x;
    long long low = 1;
    long long high = x / 2;
    long long ans = INT_MIN;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        if (mid * mid <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high=mid-1;
        }
    }
    return (int)ans;
}

int main()
{
    int n = 0;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}

// https://leetcode.com/problems/sqrtx/submissions/1176759228/
// https://leetcode.com/problems/sqrtx/submissions/1176761616/