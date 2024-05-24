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
int maximumRectangle(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int maxArea=0;
        int area=0;
        area=largestRectangleArea(matrix[0]);
        if(area>maxArea)
            maxArea=area;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++){
            if(matrix[i][j]!=0)
            matrix[i][j]=matrix[i][j]+matrix[i-1][j];
            else
                matrix[i][j]=0;
            }
            area=largestRectangleArea(matrix[i]);
            if(area>maxArea)
            maxArea=area;
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> arr(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                    arr[i][j]=1;
            }
        }
        return maximumRectangle(arr);
    }
int main(){
  
  
  
return 0;
}

// https://leetcode.com/problems/maximal-rectangle/