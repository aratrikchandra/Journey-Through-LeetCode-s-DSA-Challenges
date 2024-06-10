#include <bits/stdc++.h>
using namespace std;
    void recur(int i, int arr[], int n){
        // base case
        if(i==n)
        return;

        int j=i-1;
        int item=arr[i];
        while(j>=0 && arr[j]>item){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=item;

        recur(i+1,arr,n);
    }
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        return recur(0,arr,n);
    }
// https://www.geeksforgeeks.org/problems/insertion-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insertion-sort
int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr, n);
    cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}