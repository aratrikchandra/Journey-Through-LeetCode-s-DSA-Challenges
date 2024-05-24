#include <bits/stdc++.h>
using namespace std;
    //Heapify function to maintain heap property.
    void heapify(int arr[], int size, int ind)  
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
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i=(n-2)/2;i>=0;i--){
        heapify(arr,n,i);
    }
    }
    int deleteMax(int arr[],int last){
        if(last==0)
        return arr[last];
        
        int val=arr[0];
        arr[0]=arr[last];
        heapify(arr,last+1,0);
        return val;
    }
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        for(int i=n-1;i>0;i--)
        {
            arr[i]=deleteMax(arr,i);
        }
    }
int main(){
  
  int arr[]={10,9,8,7,6,5,4,3,2,1};
  int N=10;
  heapSort(arr,N);

  for(auto it:arr)
  cout<<it<<" ";
  
return 0;
}

// https://www.geeksforgeeks.org/problems/heap-sort/1