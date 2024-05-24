
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
int merge(vector<int> arr, int low, int mid, int high)
{
    int count=0;
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
int mergeSort(vector<int> arr, int low, int high)
{
    int count=0;
    if (low >= high)
        return count;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
    return count;
}

   vector<int> countSmaller(vector<int>& nums) {
        
    }

};

int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    Solution obj;
    vector<int> ans = obj.countSmaller(a);
    for(auto it:ans)
    cout<<it<<" ";
    return 0;
}
