#include <bits/stdc++.h>
using namespace std;
// approach 1
int reverse1(int num)
{
    int n = num;
    int revNum=0;
    while (n > 0)
    {
        int digit = n % 10;
        n = n / 10;
        revNum=revNum*10+digit;
    }
    return revNum;
}
// approcah 2
int reverse(int num){
    int n = num;
    string s="";
    while (n > 0)
    {
        int digit = n % 10;
        n = n / 10;
        s=s+to_string(digit);
    }
    int revNum=stoi(s);
    return revNum;
}
// leetcode question
    int reverse(int n) {
        int ans=0;
        while(n!=0){
            int digit=n%10;
            // out of bound check if ans*10 is valid or not
            if(ans>(INT_MAX/10) || ans < (INT_MIN)/10)
            return 0;
            ans=ans*10+digit;
            n=n/10;
        }
        return ans;
    }
    // https://leetcode.com/problems/reverse-integer/submissions/1288336224/
int main(){
  
  cout<<reverse(7865);  
return 0;
}