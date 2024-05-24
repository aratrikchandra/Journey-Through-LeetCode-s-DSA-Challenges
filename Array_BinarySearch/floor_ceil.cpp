#include <bits/stdc++.h>
using namespace std;

int getCeil(vector<int> arr, int n, int target) {
    int low = 0;
    int high = n - 1;
    int ans=-1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target){
            ans=arr[mid];
            high=mid-1;
        }
        else 
            low=mid+1;
    }
    return ans;
}
int getFloor(vector<int> arr, int n, int target) {
    int low = 0;
    int high = n - 1;
    int ans=-1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= target){
            ans=arr[mid];
			low=mid+1;
        }
        else 
            high=mid-1;
    }
    return ans;
}
pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
	int ceil=getCeil(arr,n,x);
	int floor=getFloor(arr,n,x);

	return make_pair(floor,ceil);
}
int main(){
  vector<int> arr = {3, 4, 4, 7, 8, 10};
	int n = 6, x = 5;
	pair<int, int> ans = getFloorAndCeil(arr, n, x);
	cout << "The floor and ceil are: " << ans.first
	     << " " << ans.second << endl;
	return 0;
}
// https://www.codingninjas.com/studio/problems/ceiling-in-a-sorted-array_1825401?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION