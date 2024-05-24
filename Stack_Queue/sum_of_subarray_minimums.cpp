#include <bits/stdc++.h>
using namespace std;

// better approach
int sumSubarrayMins1(vector<int> &arr)
{
    int n = arr.size();
    int mod = 1e9 + 7;
    stack<pair<int, int>> st1, st2;
    vector<int> left(n);
    vector<int> right(n);
    // finding number of elements greater in right
    for (int i = n - 1; i >= 0; i--)
    {
        int count = 1;
        while (!st1.empty() && arr[i] < st1.top().first)
        {
            count += st1.top().second;
            st1.pop();
        }
        st1.push({arr[i], count});
        right[i] = count % mod;
    }

    // finding number of elements greater in left
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while (!st2.empty() && arr[i] <= st2.top().first)
        {
            count += st2.top().second;
            st2.pop();
        }
        st2.push({arr[i], count});
        left[i] = count % mod;
    }
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = (sum + (((long long)arr[i] * left[i]) % mod * right[i]) % mod) % mod;
    }

    return int(sum % mod);
}

// optimal approach
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
int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pse=prevSmaller(arr);
    vector<int> nse=nextSmaller(arr);
    int mod=1e9+7;
    long sum=0;
    for(int i=0;i<n;i++)
    {
        int left_range_len=i-pse[i];
        int right_range_len=nse[i]-i;

        long prod=(left_range_len * right_range_len)%mod;
        prod=(prod*arr[i])%mod;
        sum= ((sum%mod) + (prod))%mod; 
    }
    return (int)sum;
}
int main()
{
    vector<int> A = {3, 1, 2, 4};

    // function call to get required result
    cout << sumSubarrayMins(A);
    return 0;
}

// https://leetcode.com/problems/sum-of-subarray-minimums/submissions/1194567812/