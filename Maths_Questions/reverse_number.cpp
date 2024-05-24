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
int main(){
  
  cout<<reverse(7865);  
return 0;
}