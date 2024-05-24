

#include <bits/stdc++.h>

using namespace std;

vector<int> findArrayIntersection(int arr1[], int arr2[], int n, int m)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            // if (ans.size() == 0 || ans.back() != arr1[i])  // we may or may not check this condition depending on the problem statement
            // {
            //     ans.push_back(arr1[i]);
            // }

            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main()

{
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3,4, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector<int> intersection = findArrayIntersection(arr1, arr2, n, m);
    cout << "intersection of arr1 and arr2 is  " << endl;
    for (auto &val : intersection)
        cout << val << " ";
    return 0;
}

// https://www.codingninjas.com/studio/problems/intersection-of-2-arrays_1082149?leftPanelTabValue=SUBMISSION
