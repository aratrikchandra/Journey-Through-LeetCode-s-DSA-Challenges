


#include<bits/stdc++.h>
using namespace std;

vector<int> printLeaders(int arr[], int n) {
    int maxVal=INT_MIN;
    vector<int> leaders;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]>maxVal)
        {
            leaders.push_back(arr[i]);
            maxVal=arr[i];
        }
    }
    reverse(leaders.begin(),leaders.end());
    return leaders;
}

int main() {
    
  // Array Initialization.
  int n = 6;
  int arr[n] = {10, 22, 12, 3, 0, 6};

  vector<int> ans = printLeaders(arr,n);
  
  
  for(int i = ans.size()-1;i>=0;i--){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  return 0;
}


// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1