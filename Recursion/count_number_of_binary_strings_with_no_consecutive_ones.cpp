#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = (1e9) + 7;
ll countStrings(int n)
{
    vector<ll> a(n + 1, -1); // for strings ending with zero
    vector<ll> b(n + 1, -1); // for strings ending with one
     // base case                         
    a[0] = b[0] = 0;
    a[1] = b[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i] = (a[i - 1] + b[i - 1])%mod;
        b[i] = a[i - 1]%mod;
    }
    return (a[n] + b[n])%mod;
}
// https://www.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1
int main()
{

    return 0;
}