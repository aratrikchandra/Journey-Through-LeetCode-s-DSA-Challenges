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
string shortestPalindrome(string s) {

        string str=s; // store the original string

        string t=s;
        reverse(t.begin(),t.end());
        s+='$';
        s+=t;
        vector<int> lps=createLPS(s);
        int n=s.size();
        int matched=lps[n-1]; // longest prefix which is also suffix(longest prefix palindrome)

        // in str longest prefix palindrome is str[0,......,matched-1];
        // remaining string which is not palindrome str[matched,.....,m-1];
        string extraChars=str.substr(matched);
        reverse(extraChars.begin(),extraChars.end());
        string ans=extraChars+str;
        return ans;
    }
// https://leetcode.com/problems/shortest-palindrome/submissions/1286626721/
int main(){
  
  
  
return 0;
}