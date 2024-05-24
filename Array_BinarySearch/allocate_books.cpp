#include <bits/stdc++.h>
using namespace std;
pair<int, int> max_and_sum(int arr[], int n)
{
    int max = arr[0];
    int sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
        sum += arr[i];
    }
    return make_pair(max, sum);
}
int countStudent(int arr[], int maxPage, int n)
{
    int count=1;
    int pageSize=arr[0];

    for(int i=1;i<n;i++)
    {
        if(pageSize+arr[i]<=maxPage)
            pageSize+=arr[i];
        else{
            count++;
            pageSize=arr[i];
        }
    }
    return count;
}
int findPages(int arr[], int n, int k)
{
    pair<int, int> val = max_and_sum(arr, n);
    // when ans is not possible
    if (n < k)
        return -1;
    int low = val.first;
    int high = val.second;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int student = countStudent(arr, mid, n);

        if (student <= k) // possible to allocate
            high=mid-1;
        else
            low=mid+1;
    }
    return low;
}
int main()
{
    int N = 4;
    int A[] = {12, 34, 67, 90};
    int k = 2;
    cout << findPages(A, N, k);
    return 0;
}
// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1