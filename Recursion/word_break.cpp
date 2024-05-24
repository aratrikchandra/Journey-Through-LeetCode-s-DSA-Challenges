#include <bits/stdc++.h>
using namespace std;
bool solve(int start, int end, string s, unordered_set<string> &st)
{
    // base case
    if (end == s.size())  // we have reached the end of the string
    {
        if (st.find(s.substr(start, end - start + 1)) != st.end()) // the last substring exists in the set
            return true;
        else
            return false;
    }
    // keeping the start point as it is and expanding the string
    if (solve(start, end + 1, s, st) == true)
        return true;

    // check if the current substring is present in the dictionary
    if (st.find(s.substr(start, end - start + 1)) != st.end())
    {
        // making recursive call for remaining part of the string other than the current word
        if (solve(end + 1, end + 1, s, st) == true)
            return true;
    }
    return false;
}
bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> st(wordDict.begin(), wordDict.end());
    return solve(0, 0, s, st);
}
int main()
{

    return 0;
}

// https://leetcode.com/problems/word-break/submissions/1225625306/