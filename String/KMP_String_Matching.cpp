#include <bits/stdc++.h>
using namespace std;

vector<int> createLPS(string &str)
{

    int n = str.size();
    vector<int> lps(n, 0);
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i < n)
    {
        if (str[i] == str[len]) // case 1
        {
            lps[i] = len + 1;
            len++;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
    return lps;
}
// This function finds out indexes where all the pattern is present inside text
vector<int> KMP_search(string &text, string &pattern)
{
    int m = text.size();
    int n = pattern.size();

    vector<int> lps=createLPS(pattern);
    vector<int> ans;

    int i = 0, j = 0;
    while (i < m)
    {
        if(text[i]==pattern[j]){
            i++;
            j++;

            if(j==n) // we found a match
            {
                ans.push_back(i-j);
                j=lps[j-1]; // to explore further presence of pattern in text
            }
        }
        else{
            if(j==0){
                i++;
            }
            else{
                j=lps[j-1];
            }
        }
    }
    return ans;
}
int strStr(string haystack, string needle)
{
    vector<int> ans=KMP_search(haystack, needle);
    if(ans.size()==0)
    return -1;
    else
    return ans[0];
}
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
int main()
{
    string haystack = "sadbutsad", needle = "sad";

    vector<int> ans = KMP_search(haystack, needle);
    cout<<ans.size()<<endl;
    for(auto it: ans){
        cout<<it<<endl;
    }
    return 0;
}