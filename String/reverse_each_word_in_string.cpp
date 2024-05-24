#include <bits/stdc++.h>
using namespace std;

void reverse(string &s,int left,int right){
    while(left<=right){
        char temp=s[left];
        s[left]=s[right];
        s[right]=temp;
        left++;
        right--;
    }
}
string reverseWords(string s) {
        int start=0;
        int end=0;

        while(end<s.length()){
            if(s[end]==' '){ // we reached after the end of an word
                reverse(s,start,end-1);
                start=end+1;
            }
            end++;
        }
        reverse(s,start,end-1); // for the last word
        return s;
}

// https://leetcode.com/problems/reverse-words-in-a-string-iii/submissions/1216646360/
int main(){
  string s = "Let's take LeetCode contest";
  cout<<reverseWords(s); 
return 0;
}