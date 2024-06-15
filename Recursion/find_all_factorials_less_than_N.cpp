#include <bits/stdc++.h>
using namespace std;
void solve(long long i, long long fact, long long N, vector<long long> &ans)
{
    // base case
    if (fact > N)
        return;

    ans.push_back(fact);
    solve(i + 1, fact * (i + 1), N, ans);
}
vector<long long> factorialNumbers(long long N)
{
    vector<long long> ans;
    long long i = 1;
    solve(1, 1, N, ans);
    return ans;
}
// https://www.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/0?problemType=functional&difficulty%5B%5D=-1&page=1&query=problemTypefunctionaldifficulty%5B%5D-1page1
int main()
{

    return 0;
}