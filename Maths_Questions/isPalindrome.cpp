#include <bits/stdc++.h>
using namespace std;
// approach 1
bool isPalindrome(int num)
{
    int n = num;
    int revNum=0;
    while (n > 0)
    {
        int digit = n % 10;
        n = n / 10;
        revNum=revNum*10+digit;
    }
    return num==revNum?true:false;
}
// approach 2(required for avoiding integer overflow)
bool isPalindrome(int num)
{
    string s = to_string(num);
    int i=0;
    int j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j])
        return false;

        i++;j++;
    }
    return true;
}
// https://leetcode.com/problems/palindrome-number/submissions/1210752060/
int main()
{

    return 0;
}
