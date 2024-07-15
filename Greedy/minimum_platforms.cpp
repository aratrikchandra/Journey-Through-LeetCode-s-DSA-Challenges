#include<bits/stdc++.h>
 using namespace std;
 
int findPlatform(int arr[], int dep[], int n)
    {
    	int count=0;
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=0,j=0;
    	int maxCount=0;
    	while(i<n){
    	    if(arr[i]<=dep[j]){
    	        count++;
    	        i++;
    	    }
    	    else{
    	        count--;
    	        j++;
    	    }
    	    
    	    maxCount=max(maxCount,count);
    	}
    	return maxCount;
    }
 
 int main()
 {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<findPlatform(arr,dep,n)<<endl;
 }

 // https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1