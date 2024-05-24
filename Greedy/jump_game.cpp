#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int> &arr)
{
    int n = arr.size();
    int coverage = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (i <= coverage)
        { // we can reach index i
            coverage = max(coverage, i + arr[i]);
            if (coverage >= n - 1)
                return true;
        }
        else
            return false;
    }
    return true;
}
int main()
{

    vector<int> arr = {2, 3, 1, 1, 4};
    cout << canJump(arr);

    return 0;
}

// https://leetcode.com/problems/jump-game/