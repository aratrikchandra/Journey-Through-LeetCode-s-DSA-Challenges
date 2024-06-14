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
    string longestPrefix(string s) {
        vector<int> lps=createLPS(s);
        int maxLen=lps[s.size()-1];
        string ans="";
        for(int i=0;i<maxLen;i++){
            ans+=s[i];
        }
        return ans;
    }
    // https://leetcode.com/problems/longest-happy-prefix/
int main(){
  
  
  
return 0;
}