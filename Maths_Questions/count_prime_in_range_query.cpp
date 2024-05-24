#include <bits/stdc++.h>
using namespace std;
vector<int> getSieve(int n)
{
    vector<int> primes(n + 1, 1); // initializing with 1
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (primes[i] == 1)
        { // then i is a prime
            for (int j = i * i; j <= n; j = j + i)
            {
                primes[j] = 0;
            }
        }
    }
    return primes;
}
void prefixSum(vector<int> &primes){
    for(int i=1;i<primes.size();i++){
        primes[i]=primes[i-1]+primes[i];
    }
}
vector<int> countPrimeInRange(vector<vector<int>> &Q){
    vector<int> primes=getSieve(1e6+1);
    prefixSum(primes);
    vector<int> ans;
    for(int i=0;i<Q.size();i++){
        int L=Q[i][0];
        int R=Q[i][1];

        int count=primes[R]-primes[L-1];
        ans.push_back(count);
    }
    return ans;
}
int main(){
  vector<vector<int>> Q={{1,100},{100,200}};
  vector<int> ans=countPrimeInRange(Q);
  for(auto it:ans)
  cout<<it<<" ";
return 0;
}