#include <bits/stdc++.h>
using namespace std;
// recursive approach
void bubbleSort(int arr[], int end) {
       // base case
       if(end==0) // only one element left i.e. arr[0]
       return;
        bool flag=false;
       for(int j=0;j<=end-1;j++){
        if(arr[j]>arr[j+1])
        {
            swap(arr[j],arr[j+1]);
            flag=true;
        }
       }
       if(flag==false) // no more swaps required
       return;

       return bubbleSort(arr, end-1);
    }
// https://www.geeksforgeeks.org/problems/bubble-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bubble-sort
int main(){
  
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr, n-1);
    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
  
return 0;
}