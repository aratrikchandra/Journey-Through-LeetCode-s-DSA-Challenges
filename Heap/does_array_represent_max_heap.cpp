#include <bits/stdc++.h>
using namespace std;
bool isMaxHeap(int arr[], int n)
    {
        for(int i=0;i<=(n-2)/2;i++){
            int left=2*i+1;
            if(arr[i]<arr[left])
            return false;
            int right=2*i+2;
            if(arr[i]<arr[right])
            return false;
        }
        return true;
    }
int main(){
  
  int arr[] = {90, 15, 10, 17, 12, 2};
  int n=6;
  cout<<isMaxHeap(arr,n);
  
return 0;
}

// https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1