#include <bits/stdc++.h>
using namespace std;

// optimal 1 (using set)
int lengthOfLongestSubstring1(string s)
{
    int left = 0;
    int right = 0;
    int len = 0;
    unordered_set<char> us;
    for (right = 0; right < s.size(); right++)
    {
        if (us.find(s[right]) != us.end())
        { // s[right] already preset in set

            while (left <= right && us.find(s[right]) != us.end())
            {
                us.erase(s[left]);
                left++;
            }
        }
        us.insert(s[right]);
        len = max(len, right - left + 1);
    }
    return len;
}
// optimal 2 (using map)
int lengthOfLongestSubstring(string s)
{
    int left = 0;
    int right = 0;
    int len = 0;
    unordered_map<char, int> umap;
    for (right = 0; right < s.size(); right++)
    {
        if (umap.find(s[right]) != umap.end()) // element already present
        {
            int ind = umap[s[right]];
            if (ind < left)
            {
                umap[s[right]] = right;
            }
            else
            {
                left = ind + 1;
                umap[s[right]] = right;
            }
        }
        else
        {
            umap[s[right]]=right;
        }
        len = max(len, right - left + 1);
    }
    return len;
}
int main()
{
    string str = "takeUforward";
    cout << "The length of the longest substring without repeating characters is " << lengthOfLongestSubstring(str);
    return 0;
}

// https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/1201661779/