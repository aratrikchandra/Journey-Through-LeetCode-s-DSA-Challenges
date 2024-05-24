#include <bits/stdc++.h>
using namespace std;

// version 1 (where number of pos and neg is equal)
vector<int> rearrangeArray(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, 0);
    int posIndex = 0;
    int negIndex = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
        else if (arr[i] < 0)
        {
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
    }
    return ans;
}

// version 2 (where number of pos and neg is not equal)
void rearrange(int *arr, int n)
{
  vector<int> pos, neg;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)  // Modified this condition to include zero as a positive number
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }

    int pSize = pos.size();
    int nSize = neg.size();

    int i = 0, j = 0, k = 0;   // like merge function in merge sort

    while (i < pSize && j < nSize)
    {
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }

    while (i < pSize)
    {
        arr[k++] = pos[i++];
    }

    while (j < nSize)
    {
        arr[k++] = neg[j++];
    }
}

int main()
{

    // Array Initialisation.

    // vector<int> A = {1, 2, -4, -5};

    // vector<int> ans = rearrangeArray(A);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    int Arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n = 10;
    rearrange(Arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }

    return 0;
}

// https://leetcode.com/problems/rearrange-array-elements-by-sign/submissions/1165145066/

// https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab