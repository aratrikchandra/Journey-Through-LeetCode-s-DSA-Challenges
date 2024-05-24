#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void merge(int arr[], int low, int mid, int high)
    {
        int i = low;
        int j = mid + 1;
        vector<int> temp;
        while (i <= mid && j <= high)
        {
            if (arr[i] <= arr[j])
            {
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
        }

        while(i<=mid)
        {
            temp.push_back(arr[i]);
            i++;
        }

        while(j<=high)
        {
            temp.push_back(arr[j]);
            j++;
        }

        for(int i=low;i<=high;i++)
        {
            arr[i]=temp[i-low];
        }
    }

public:
    void mergeSort(int arr[], int low, int high)
    {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
};

int main()
{
    int arr[] = {9, 4, 7, 6, 3, 1, 5};
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    Solution obj;
    obj.mergeSort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/merge-sort/1