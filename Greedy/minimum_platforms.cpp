#include<bits/stdc++.h>
 using namespace std;
 
 int countPlatforms(int n,int arr[],int dep[])
 {
    sort(arr,arr+n);
    sort(dep,dep+n);

    int maxCount=1;
    int i=1;
    int j=0;
    int count=1;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j])
        {
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        if(count>maxCount)
        maxCount=count;
    }
    return maxCount;
 }
 
 int main()
 {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<countPlatforms(n,arr,dep)<<endl;
 }

 // https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1