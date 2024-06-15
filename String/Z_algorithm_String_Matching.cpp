#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> createZarray(string &str){
        int n=str.size();
        vector<int> z(n,-1);
        z[0]=0;
        int left=0;
        int right=0;

        for(int i=1;i<n;i++){
            if(i>right){ // i doesn't fall inside the interval
            left=right=i;
            while(right<n && str[right-left]==str[right])
            right++;

            right--; // matched prefix substring str[left,....,right-1] right
            z[i]=right-left+1;
        }
        else{
            // i falls inside the boundary
            if(z[i-left]<right-i+1){
                z[i]=z[i-left];
            }
            else{
                left=i;
                while(right<n && str[right-left]==str[right])
                right++;

                right--; // matched prefix substring str[left,....,right-1] right
                z[i]=right-left+1;
            }
        }
    }
    return z;
}
    vector<int> zAlgorithmSearch(string &text, string &pattern){
        vector<int> ans; // stores starting indexes of matched pattern in the text string
        int n=pattern.size();
        text=pattern+'$'+text;
        vector<int> z=createZarray(text);

        for(int i=n+1;i<text.size();i++){
            if(z[i]==n){
                ans.push_back(i-n-1);
            }
        }
        return ans;
    }
    int strStr(string haystack, string needle) {
        vector<int> ans=zAlgorithmSearch(haystack,needle);
        if(ans.size()==0)
        return -1;
        else
        return ans[0];
    }
};
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/1288762125/
int main(){
  
  
  
return 0;
}