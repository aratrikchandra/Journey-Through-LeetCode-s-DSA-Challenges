#include <bits/stdc++.h>
using namespace std;

int partition(int low, int high, vector<int> &arr){
    int i=low;
    int j=high;

    int pivot=arr[low];

    while(i<j){

        while(arr[i]<=pivot && i<=high-1) // to avoid array out of bound access
        i++;

        while(arr[j]>pivot && j>=low+1) // to avoid array out of bound access
        j--;

        if(i<j)
        swap(arr[i],arr[j]);
    }

    swap(pivot,arr[j]);
    return j;
}
void QuickSort(int low, int high, vector<int> &arr){
    // base case
    if(low>=high)
    return;

    int j=partition(low,high,arr);
    QuickSort(low,j-1,arr);
    QuickSort(j+1,high,arr);
}
vector<int> quickSort(vector<int> arr)
{
     QuickSort(0,arr.size()-1,arr);
     return arr;
}
// https://www.naukri.com/code360/problems/quick-sort_983625?leftPanelTabValue=SUBMISSION
int main(){
  
  
  
return 0;
}