#include <bits/stdc++.h>
using namespace std;

long long power(long long base, long long exp) // binary exponentiation
{
   if (exp <= 0) // base case
        return 1;
    long long temp = power(base, exp / 2);
    if (exp % 2 == 1)
    {
        return temp * temp * base;
    }
    else
    {
        return temp * temp;
    }
}
int NthRoot(int n, int m)
{
    if (m <= 1) // important edge case
        return m;
    long long low = 1;
    long long high = m / n;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long val=power(mid, n);
        if((int)val==m)
          return (int)mid;
        if (val < m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n = 3, m = 64;
    int ans = NthRoot(n, m);
    cout << "The answer is: " << ans << "\n";

    // cout<<power(2,12);
    return 0;
}