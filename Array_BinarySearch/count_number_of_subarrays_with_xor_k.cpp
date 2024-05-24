


#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> arr, int k) {
    int n=arr.size();
    unordered_map<int,int> umap;
    umap[0]=1;
    int preXor=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        preXor=preXor ^ arr[i];
        int target=preXor ^ k;
        count+=umap[target];
        umap[preXor]++;
    }
    return count;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}

// https://www.interviewbit.com/problems/subarray-with-given-xor/