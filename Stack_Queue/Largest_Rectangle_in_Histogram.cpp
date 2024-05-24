#include <bits/stdc++.h>
using namespace std;
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
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();

        if (!st.empty())
            ans[i] = st.top();

        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int maxArea = 0;
    vector<int> pse = prevSmaller(heights);
    vector<int> nse = nextSmaller(heights);
    for (int i = 0; i < n; i++)
    {
        int leftBoundary = pse[i] + 1;
        int rightBoundary = nse[i] - 1;

        int width = rightBoundary - leftBoundary + 1;
        int area = heights[i] * width;
        if (area > maxArea)
            maxArea = area;
    }
    return maxArea;
}
int main()
{

    return 0;
}

// https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/1195806729/