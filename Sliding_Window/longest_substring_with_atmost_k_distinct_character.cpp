#include <bits/stdc++.h>
using namespace std;
int kDistinctChars(int k, string &str)
{
    int n = str.size();

    int left = 0;
    int right = 0;
    int maxLen = 0;
    unordered_map<char, int> umap;

    for (right = 0; right < n; right++)
    {
        umap[str[right]]++;

        while (left <= right && umap.size() > k)
        {
            umap[str[left]]--;
            if (umap[str[left]] == 0)
                umap.erase(str[left]);

            left++;
        }

        maxLen=max(maxLen,right-left+1);
    }
    return maxLen;
}

int main(){
  
  string str="abcddefg";
  int k=3;
  cout<<kDistinctChars(k,str);
  
return 0;
}

// https://www.codingninjas.com/studio/problems/longest-substring-with-at-most-k-distinct-characters_2221410?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM