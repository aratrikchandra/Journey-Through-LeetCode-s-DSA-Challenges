#include <bits/stdc++.h>
using namespace std;
// two pointer approach
void solve(vector<int> &arr,int left,int right){
    if(left>=right){
        return;
    }
    swap(arr[left],arr[right]);
    solve(arr,left+1,right-1);
}
vector<int> reverseArray(int n, vector<int> &arr)
{
    solve(arr,0,n-1);
    return arr;
}
// https://www.naukri.com/code360/problems/reverse-an-array_8365444?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION
int main(){
  
  
  
return 0;
}