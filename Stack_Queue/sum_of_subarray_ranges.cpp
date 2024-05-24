#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

// subarray min sum
vector<int> prevSmaller(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n, -1); // if pse not exist then take -1
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        if (!st.empty())
            ans[i] = st.top();

        st.push(i);
    }
    return ans;
}
vector<int> nextSmaller(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n, n); // if nse not exist then take n(len of arr)
    for (int i = n-1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();

        if (!st.empty())
            ans[i] = st.top();

        st.push(i);
    }
    return ans;
}
long long sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pse=prevSmaller(arr);
    vector<int> nse=nextSmaller(arr);
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        int left_range_len=i-pse[i];
        int right_range_len=nse[i]-i;

        long long prod=(left_range_len * right_range_len);
        prod=(prod*arr[i]);
        sum= ((sum) + (prod)); 
    }
    return sum;
}
// subarray max sum
vector<int> prevGreater(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n, -1); // if pse not exist then take -1
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
            st.pop();

        if (!st.empty())
            ans[i] = st.top();

        st.push(i);
    }
    return ans;
}
vector<int> nextGreater(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n, n); // if nse not exist then take n(len of arr)
    for (int i = n-1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
            st.pop();

        if (!st.empty())
            ans[i] = st.top();

        st.push(i);
    }
    return ans;
}
long long sumSubarrayMaxs(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pse=prevGreater(arr);
    vector<int> nse=nextGreater(arr);
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        int left_range_len=i-pse[i];
        int right_range_len=nse[i]-i;

        long long prod=(left_range_len * right_range_len);
        prod=(prod*arr[i]);
        sum= ((sum) + (prod)); 
    }
    return sum;
}
long long subArrayRanges(vector<int>& arr) {
        return sumSubarrayMaxs(arr)-sumSubarrayMins(arr);
    }
};
int main(){
  
  
  
return 0;
}
// https://leetcode.com/problems/sum-of-subarray-ranges/submissions/1194576064/