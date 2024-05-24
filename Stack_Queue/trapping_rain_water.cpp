#include <bits/stdc++.h>
using namespace std;

// better approach
int trap1(vector<int> &height)
{
    int n = height.size();
    vector<int> prefix(n), suffix(n);
    int leftMax = 0;
    int rightMax = 0;
    for (int i = 0; i < n; i++)
    {
        if (leftMax < height[i])
        {
            leftMax = height[i];
        }
        prefix[i] = leftMax;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (rightMax < height[i])
        {
            rightMax = height[i];
        }
        suffix[i] = rightMax;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += min(prefix[i], suffix[i]) - height[i];
    }
    return sum;
}
// optimal approach (using two pointers)
int trap(vector<int> &height)
{
    int n = height.size();

    int left = 0;
    int right = n - 1;
    int sum = 0;
    int leftMax = 0;
    int rightMax = 0;
    while (left <= right)
    {
        if (height[left] <= height[right])
        {
            if (leftMax < height[left])
            {
                leftMax = height[left];
            }
            else
            sum=sum+(leftMax-height[left]);

            left++;
        }
        else
        {
            if (rightMax < height[right])
            {
                rightMax = height[right];
            }
            else
            sum+=rightMax-height[right];

            right--;
        }
    }
    return sum;
}
int main()
{
    vector<int> arr;
    arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "The water that can be trapped is " << trap(arr) << endl;
}

// https://leetcode.com/problems/trapping-rain-water/submissions/1193817697/