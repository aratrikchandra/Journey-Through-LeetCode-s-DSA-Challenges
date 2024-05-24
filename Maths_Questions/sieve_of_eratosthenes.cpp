#include <bits/stdc++.h>
using namespace std;
int countPrimes(int n) {
        if(n<=1)
        return 0;
        vector<int> primes(n, 1); // initializing with 1
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i < n; i++)
    {
        if (primes[i] == 1)
        { // then i is a prime
            for (int j = i * i; j < n; j = j + i)
            {
                primes[j] = 0;
            }
        }
    }
    int count=0;
    for(int i=2;i<n;i++){
        if(primes[i]==1){
            count++;
        }
    }
    return count;
    }
int main()
{
    cout << countPrimes(17);

    return 0;
}