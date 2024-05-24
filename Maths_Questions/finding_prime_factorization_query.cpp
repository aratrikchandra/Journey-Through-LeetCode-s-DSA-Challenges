#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> primeFactorization(vector<int> &Q){
    int n=1e6; // max value
    vector<int> spf(n+1);
    spf[0] = spf[1] = 0;
    for(int i=2;i<=n;i++)
    spf[i]=i;
    for (int i = 2; i * i <= n; i++)
    {
        if (spf[i] == i)
        { // then i is a prime
            for (int j = i * i; j <= n; j = j + i)
            {
                if(spf[j]==j) // if j does not have any previous spf value
                spf[j] = i;
            }
        }
    }
    vector<vector<int>> ans;
    for(int i=0;i<Q.size();i++){
      int num=Q[i];
      vector<int> temp;
      while(num!=1){
        temp.push_back(spf[num]);
        num=num/spf[num];
      }
      ans.push_back(temp);
    }
    return ans;
}
int main(){
    vector<int> Q={80,70,20,1000000};
  vector<vector<int>> ans=primeFactorization(Q);
  for(auto it1:ans){
    for(auto it:it1){
        cout<<it<<" ";
    }
    cout<<endl;
  }
return 0;
}