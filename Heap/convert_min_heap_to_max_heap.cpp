#include <bits/stdc++.h>
using namespace std;
 void heapify(vector<int> &arr,int ind,int size)
    {
        int j = 2 * ind + 1;
        int item = arr[ind];

        while (j < size)
        {
            if (j + 1 < size && arr[j] < arr[j + 1]) // if the right child is larger
                j++;
            
            if(arr[j]<=item)
            break;

            arr[(j-1)/2]=arr[j];
            j=2*j+1;
        }
        arr[(j-1)/2]=item;
    }
void convertMinToMaxHeap(vector<int> &arr, int N){
    for(int i=(N-2)/2;i>=0;i--){
        heapify(arr,i,N);
    }
}
int main(){
  
  
  
return 0;
}

// https://www.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1