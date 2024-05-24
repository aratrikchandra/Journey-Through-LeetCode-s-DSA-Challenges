#include <bits/stdc++.h>
using namespace std;

class meeting
{ // represent each meeting in this form
public:
    int start;
    int end;
    int number;

    // constructor
    meeting(int start1, int end1, int number1)
    {
        start = start1;
        end = end1;
        number = number1;
    }
};
bool static comp(meeting m1, meeting m2) // sorting based on desc. order of end time
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else
    {
        if (m1.number < m2.number)
            return true;
        else
            return false;
    }
}
int maxMeetings(int start[], int end[], int n)
{
    vector<int> result;
    int ans = 0;
    vector<meeting> arr;
    for (int i = 0; i < n; i++)
    {
        meeting m = meeting(start[i], end[i], i + 1);
        arr.push_back(m);
    }
    sort(arr.begin(), arr.end(), comp);
    // first meeting will always be performed
    ans++;
    result.push_back(arr[0].number);
    int lastEndTime = arr[0].end;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].start > lastEndTime)
        {
            ans++;
            result.push_back(arr[i].number);
            lastEndTime = arr[i].end;
        }
    }
    for (auto it : result)
        cout << it << " ";
    cout << endl;

    return ans;
}
int main()
{
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 5, 7, 9, 9};
    cout << maxMeetings(start, end, n);
    return 0;
}

// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1