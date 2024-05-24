
#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
long long merge(long long arr[], long long low, long long mid, long long high)
{
    long long count=0;
    long long i = low;
    long long j = mid + 1;
    vector<long long> temp;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            count+=(mid-i+1);
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= high)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return count;
}
    private:
long long mergeSort(long long arr[], long long low, long long high)
{
    long long count=0;
    if (low >= high)
        return count;
    long long mid = (low + high) / 2;
    count+=mergeSort(arr, low, mid);
    count+=mergeSort(arr, mid + 1, high);
    count+=merge(arr, low, mid, high);
    return count;
}

  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr,0,N-1);
    }

};

int main()
{
    long long a[] = {5, 4, 3, 2, 1};
    long long n = 5;
    Solution obj;
    long long cnt = obj.inversionCount(a, n);
    cout << "The number of inversions are: "
         << cnt << endl;
    return 0;
}
