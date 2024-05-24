#include <bits/stdc++.h>
using namespace std;

// digit extraction
vector<int> digitExtraction(int n){
    vector<int> ans;
    while(n>0){
        int digit=n%10;
        ans.push_back(digit);
        n=n/10;
    }
    return ans;
}
int countDigits(int n){
	return (int)(log10(n)+1);	
}
int main(){
  
  vector<int> ans=digitExtraction(7798);
  for(auto it:ans){
    cout<<it<<" ";
  }
  
return 0;
}