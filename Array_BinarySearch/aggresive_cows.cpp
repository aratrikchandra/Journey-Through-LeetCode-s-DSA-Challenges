#include <bits/stdc++.h>
using namespace std;
pair<int, int> max_and_min(vector<int> arr, int n)
{
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
        else if (min > arr[i])
            min = arr[i];
    }
    return make_pair(max, min);
}
bool isPossible(vector<int> arr, int minGap, int k, int n)
{
    int cows = 1;
    int last = arr[0];
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] - last) >= minGap)
        {
            cows++;
            last = arr[i];
        }

        if (cows >= k)
            return true;
    }
    return false;
}
int aggressiveCows(vector<int> stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    pair<int, int> val = max_and_min(stalls, n);
    int low = 1;
    int high = (val.first - val.second);
    //int ans = INT_MIN;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        bool flag = isPossible(stalls, mid, k, n);
        if (flag)
        {
           // ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    //return ans;
    return high;
}
int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}

// https://www.codingninjas.com/studio/problems/aggressive-cows_1082559?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTabValue=SUBMISSION