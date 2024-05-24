#include <bits/stdc++.h>
using namespace std;

 double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size();
        int n2=arr2.size();
        if(n2<n1) return findMedianSortedArrays(arr2,arr1);
        int low=0;
        int high=n1;
        int left=(n1+n2+1)/2;
        int l1,l2,r1,r2;
        while(low<=high)
        {
            int mid1=low+(high-low)/2;
            int mid2=left-mid1;
            
            l1=mid1==0?INT_MIN:arr1[mid1-1];
            l2=mid2==0?INT_MIN:arr2[mid2-1];
            r1=mid1==n1?INT_MAX:arr1[mid1];
            r2=mid2==n2?INT_MAX:arr2[mid2];
            if(l1<=r2 && l2<=r1) // valid arrangement
            {
                if((n1+n2)%2)
                    return double(max(l1,l2));
                else{
                    double val=(max(l1,l2)+min(r1,r2))/2.0;
                    return val;
                }
            }

            else if(l1>r2)
                high=mid1-1;
            else
                low=mid1+1;
        }
        return 0.0;
}

int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << findMedianSortedArrays(a, b) << '\n';
}

// https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/1181072647/