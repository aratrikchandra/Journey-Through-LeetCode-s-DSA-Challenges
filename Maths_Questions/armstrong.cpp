#include <bits/stdc++.h>
using namespace std;
bool checkArmstrong(int num){
	int n=num;
		int numOfDigits=(int)(log10(n)+1);
    int sum=0;
    while(n>0){
        int digit=n%10;
        sum=sum+int(pow(digit,numOfDigits));
        n=n/10;
    }
    return num==sum?true:false;
}
// https://www.codingninjas.com/studio/problems/check-armstrong_589?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION
int main(){
  
return 0;
}