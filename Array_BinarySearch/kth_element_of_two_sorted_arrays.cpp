#include <bits/stdc++.h>
using namespace std;
int kthElement(int arr1[], int arr2[], int n1, int n2, int k)
{
    if (n2 < n1)
        return kthElement(arr2, arr1, n2, n1, k);
    int low = max(0, k - n2);
    int high = min(k, n1);
    int left = k;
    int l1, l2, r1, r2;
    while (low <= high)
    {
        int mid1 = low + (high - low) / 2;
        int mid2 = left - mid1;

        l1 = mid1 == 0 ? INT_MIN : arr1[mid1 - 1];
        l2 = mid2 == 0 ? INT_MIN : arr2[mid2 - 1];
        r1 = mid1 == n1 ? INT_MAX : arr1[mid1];
        r2 = mid2 == n2 ? INT_MAX : arr2[mid2];
        if (l1 <= r2 && l2 <= r1) // valid arrangement
        {
            return max(l1, l2);
        }

        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}
int main()
{
    int arr1[] = {100, 112, 256, 349, 770};
    int arr2[] = {72, 86, 113, 119, 265, 445, 892};
    int k = 7;
    cout << kthElement(arr1, arr2, 5, 7, k);

    return 0;
}