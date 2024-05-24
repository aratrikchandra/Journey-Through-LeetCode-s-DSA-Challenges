#include <bits/stdc++.h>
using namespace std;

// Moore's voting algo
int majorityElement(vector<int> arr)
{
    int n = arr.size();

    int count = 0;
    int majority;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            majority = arr[i];
        }
        if (arr[i] == majority)
            count++;
        else
            count--;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == majority)
            cnt++;
    }
    if (cnt > floor(n / 2))
        return majority;
    else
        return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}


// https://leetcode.com/problems/majority-element/submissions/