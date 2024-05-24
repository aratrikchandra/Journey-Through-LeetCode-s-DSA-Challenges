#include <bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();

        int i=0;
        int j=0;
        int count=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i<n && j<m)
        {
            if(g[i]<=s[j])
            {
                count++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return count;
    }
int main(){
  
  vector<int>  g ={1,2}, s = {1,2,3};
  cout<<findContentChildren(g,s);
return 0;
}

// https://leetcode.com/problems/assign-cookies/submissions/1197392295/