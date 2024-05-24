#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> arr)
{
    int n = arr.size(); // size of the array

    int count1 = 0;
    int count2 = 0;

    int element1;
    int element2;

    for (int i = 0; i < n; i++)
    {
        if (count1 == 0 && arr[i] != element2) // edge case
        {
            element1 = arr[i];
            count1=1;
        }
        else if (count2 == 0 && arr[i] != element1) // edge case
        {
            element2 = arr[i];
            count2=1;
        }
        else if (element1 == arr[i])
        {
            count1++;
        }
        else if (element2 == arr[i])
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    // verifying our potential majority elements
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element1)
            cnt1++;
        else if (arr[i] == element2)
            cnt2++;
    }
    vector<int> ans;
    if (cnt1 > floor(n / 3))
        ans.push_back(element1);
    if (cnt2 > floor(n / 3))
        ans.push_back(element2);

    return ans;
}

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}

// https://leetcode.com/problems/majority-element-ii/submissions/1168994185/