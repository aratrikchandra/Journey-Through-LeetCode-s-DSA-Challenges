#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int>& arr) {
    int n=arr.size();
    int low=0;
    int mid=0;
    int high=n-1;

    while(mid<=high)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[low],arr[mid]);
            low++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid],arr[high]);
            high--;
            break;
        default:
            break;
        }
    }

}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/sort-colors/submissions/1164191290/