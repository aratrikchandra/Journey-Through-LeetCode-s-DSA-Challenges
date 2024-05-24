#include <bits/stdc++.h>
using namespace std;
vector<int> findPrimes(int n)
{
    vector<int> ans;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        { // i  is a prime factor of n
            ans.push_back(i);
            while (n % i == 0)
            { // while i divides n
                n = n / i;
            }
        }
    }
    // edge case(if n is prime itself)
    if(n!=1){
        ans.push_back(n);
    }
    return ans;
}
int main()
{
    vector<int> ans = findPrimes(780);
    for (auto it : ans)
        cout << it << " ";

    return 0;
}

// https://www.codingninjas.com/studio/problems/prime-factorisation_1760849?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION