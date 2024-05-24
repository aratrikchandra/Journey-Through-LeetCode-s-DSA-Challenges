


#include <bits/stdc++.h>
using namespace std;


// better solution
int longestSuccessiveElements1(int arr[], int n) {

   sort(arr,arr+n);
    int count=0;
    int maxCount=0;
    int lastSmaller=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]-1 == lastSmaller)
        {
            count++;
            lastSmaller=arr[i];
        }
        else if(arr[i] == lastSmaller)
        {
            // skip
        }
        else if(arr[i] != lastSmaller)
        {
            count=1;
            lastSmaller=arr[i];
        }

        maxCount=max(count,maxCount);
    }
    return maxCount;
}
int longestSuccessiveElements(int arr[], int n) {
    unordered_set<int> us;

    for(int i=0;i<n;i++)
    {
        us.insert(arr[i]);
    }
    int count=0;
    int maxCount=0;

    for(auto it: us)
    {
        if(us.find(it-1)==us.end()) // "it" can be a starting element
        {
            int x=it;
            int i=1;
            count=1;
            while(us.find(x+i)!=us.end()){
                i++;
                count++;
            }
            maxCount=max(maxCount,count);
        }
    }
    return maxCount;
 }


int main()
{
    int a[] = {100, 200, 1, 2, 3, 4};
    int n=6;
    int ans = longestSuccessiveElements(a,n);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}

// https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1