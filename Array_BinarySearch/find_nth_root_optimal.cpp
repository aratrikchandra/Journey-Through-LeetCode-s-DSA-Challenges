#include <bits/stdc++.h>
using namespace std;

int power(long long base, int exp, int m) // should use optimal method of exponentiation for this problem
{
    long long ans = 1;
    for (int i = 1; i <= exp; i++)
    {
        ans = ans * base;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 0;
    else
        return 1;
}
int NthRoot(int n, int m)
{
    if (m <= 1) // important edge case
        return m;
    int low = 1;
    int high = m / n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int val = power(mid, n,m);
        if (val == 0)
            return mid;
        if (val ==1)
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
    int n = 3, m = 69;
    int ans = NthRoot(n, m);
    cout << "The answer is: " << ans << "\n";

    // cout<<power(2,12);
    return 0;
}
// https://www.codingninjas.com/studio/problems/nth-root-of-m_1062679?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION