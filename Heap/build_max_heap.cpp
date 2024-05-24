#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
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
vector<int> buildHeap(vector<int> arr, int n)
{	
	for(int i=(n-2)/2;i>=0;i--){
        heapify(arr,i,n);
    }
	return arr;
}
int main(){
  
  
  
return 0;
}

// https://www.codingninjas.com/studio/problems/build-heap_975375?leftPanelTabValue=SUBMISSION