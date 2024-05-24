#include <bits/stdc++.h>
using namespace std;

void leftRotate(int arr[], int n, int d) {
        // code here
        int steps=d%n;
        
        reverse(arr,arr+steps);
        reverse(arr+steps,arr+n);
        reverse(arr,arr+n);
    }

// https://www.geeksforgeeks.org/problems/reversal-algorithm5340/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reversal-algorithm