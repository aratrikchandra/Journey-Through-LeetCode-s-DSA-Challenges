#include <bits/stdc++.h>
using namespace std;
    //Function to count the frequency of all elements from 1 to N in the array.
void frequencyCount(vector<int>& arr,int n, int p)
    { 
        p++; // this is the modulo value
        for(int i=0;i<n;i++){
            int index=arr[i]%p-1; // retrieve actual element
            if(index>=0 && index<n) // without this Abort signal from abort(3) (SIGABRT) is coming
            arr[index]=arr[index]+p; // storing frequency
        }

        for(int i=0;i<n;i++){
            arr[i]=arr[i]/p;
        }
    }
// https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0
int main(){
  
  
  
return 0;
}