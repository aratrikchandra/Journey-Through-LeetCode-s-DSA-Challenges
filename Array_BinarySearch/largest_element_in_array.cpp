#include <bits/stdc++.h> 
using namespace std;

int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
         max=arr[i];
    }

    return max;
}
