#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n) {
    // bubble sort
    int pass=0;
    for(int i=1;i<=n-1;i++)
    {
        bool flag=0;
        for(int j=1;j<=n-i;j++)
        {
            if(arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
                flag=1;
            }
        }
        pass++;
        if(flag==0)
            break;
    }

    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    cout<<"Number of pass "<<pass<<endl;
}

int main()
{
    // int arr[] = {13, 46, 24, 52, 20, 9};
    int arr[] = {13, 6, 4, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubble_sort(arr, n);
    return 0;

}