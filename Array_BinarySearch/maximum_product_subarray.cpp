#include <bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int> &arr) {
   int n=arr.size();
   int preProduct=1;
   int suffProduct=1;
   int maxProduct=INT_MIN;

   for(int i=0;i<n;i++)
   {
    preProduct=preProduct*arr[i];
    suffProduct=suffProduct*arr[n-1-i];
    maxProduct=max(maxProduct,max(preProduct,suffProduct));

    if(preProduct==0)
        preProduct=1;
    if(suffProduct==0)
        suffProduct=1;
   }
   return maxProduct;
}

int main()
{
    vector<int> arr = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray is: "
         << maxProductSubArray(arr) << "\n";
    return 0;
}

// https://leetcode.com/problems/maximum-product-subarray/submissions/1172044524/