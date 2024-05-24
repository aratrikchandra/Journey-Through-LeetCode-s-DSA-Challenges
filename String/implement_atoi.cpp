#include <bits/stdc++.h>
using namespace std;
    int myAtoi(string s) {
        int n=s.length();
        int i=0;
        while(i<n && (s[i]==' ' || s[i]=='\t')){
            i++;
        }
        // edge case
        if(i==n) // after removing leading spaces the string is empty
        return 0;
        bool negative=false;
        if(s[i]=='-'){
            negative=true;
            i++;
        }
        else if(s[i]=='+'){
            negative=false;
            i++;
        }
        long ans=0;
        for(int j=i;j<n;j++){
            if(s[j]>='0' && s[j]<='9'){ // s[j] is valid digit
                int digit=s[j]-'0';
                ans=ans*10+digit;
                if(negative==true){
                    long check=-ans;
                    if(check<=INT_MIN)
                    return INT_MIN;
                }else{
                    if(ans>=INT_MAX)
                    return INT_MAX;
                }
            }
            else{
                break;
            }
        }
        return negative?-ans:ans;
    }
// https://leetcode.com/problems/string-to-integer-atoi/submissions/1217973015/
int main(){
  
  string s="42";
  cout<<myAtoi(s);
  
return 0;
}