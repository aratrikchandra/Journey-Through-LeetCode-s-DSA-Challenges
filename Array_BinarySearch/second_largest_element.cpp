#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int> &arr,int n)
{
        int largest=arr[0];
    int second_largest=INT_MIN;

    for(int i=1;i<n;i++)
    {
        if(largest < arr[i])
        {
            second_largest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>second_largest)
        {
            second_largest=arr[i];
        }
    }

    if(second_largest==INT_MIN)
     return -1;
     else
     return second_largest;
}

int secondSmallest(vector<int> &arr,int n)
{
        int smallest=arr[0];
    int second_smallest=INT_MAX;

    for(int i=1;i<n;i++)
    {
        if(smallest > arr[i])
        {
            second_smallest=smallest;
            smallest=arr[i];
        }
        else if(arr[i]>smallest && arr[i]<second_smallest)
        {
            second_smallest=arr[i];
        }
    }

    if(second_smallest==INT_MAX)
     return -1;
     else
     return second_smallest;
}

vector<int> getSecondOrderElements(int n, vector<int> arr) {
    // Write your code here.
    vector<int> ans;
    ans.push_back(secondLargest(arr,n));
    ans.push_back(secondSmallest(arr,n));
    return ans;
}
