#include <bits/stdc++.h>
using namespace std;

// optimal 1:
void merge1(long long arr1[], long long arr2[], int n, int m)
{
    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right]) // arr1[left] should be in arr2 and similarly arr2[right] should be in arr1
        {
            swap(arr1[left], arr2[right]);
        }
        else
        {
            break;
        }
        left--;
        right++;
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

// optimal 2 (using gap method)
void merge(long long arr1[], long long arr2[], int n, int m)
{
    // code here
    int len = n + m;
    int gap = (len / 2) + (len % 2);
    int left, right;
    while (gap > 0)
    {
        left = 0;
        right = left + gap;
        while (right < n + m)
        {
            // if left is in arr1 and right is in arr2
            if (left < n && right >= n)
            {
                if (arr1[left] > arr2[right - n])
                    swap(arr1[left], arr2[right - n]);
            }
            // if left and right both in arr1
            else if (right < n)
            {
                if (arr1[left] > arr1[right])
                    swap(arr1[left], arr1[right]);
            }
            else
            { // if left and right both in arr2
                if (arr2[left - n] > arr2[right - n])
                    swap(arr2[left - n], arr2[right - n]);
            }
            left++;
            right++;
        }
        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }
}

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: "
         << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
