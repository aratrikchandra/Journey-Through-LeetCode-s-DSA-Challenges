#include<bits/stdc++.h>
using namespace std;
vector<int> MinimumCoins(int amount)
{
    int coins[]={1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> ans;
    for(int i=8;i>=0;i--){
        while(coins[i]<=amount){
            ans.push_back(coins[i]);
            amount=amount-coins[i];
        }
    }
    return ans;
}
int main() {
  int V = 4998;
  vector < int > ans=MinimumCoins(V);
  cout<<"The minimum number of coins is "<<ans.size()<<endl;
  cout<<"The coins are "<<endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}

// https://www.codingninjas.com/studio/problems/find-minimum-number-of-coins_975277?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION