#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t)
{
    int n = s.size();
    int m = t.size();

    unordered_map<char, int> hash;
    for (int i = 0; i < m; i++)
    {
        hash[t[i]]++;
    }

    int l = 0;
    int r = 0;
    int minLen = INT_MAX;
    int start = -1;
    int count = 0;
    while (r < n)
    {
        if (hash[s[r]] > 0)
        {
            count++;
        }
        hash[s[r]]--;

        while (count == m)
        {
            if (r - l + 1 < minLen)
            {
                minLen = r - l + 1;
                start = l;
            }
            hash[s[l]]++;
            if (hash[s[l]] > 0)
            {
                count = count - 1;
            }
            l++;
        }

        r++;
    }
    if (start == -1)
        return "";
    return s.substr(start, minLen);
}
// https://leetcode.com/problems/minimum-window-substring/submissions/1319441437/
int main()
{
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t);
    return 0;
}