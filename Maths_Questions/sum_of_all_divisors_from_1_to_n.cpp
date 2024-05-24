#include <bits/stdc++.h>
using namespace std;

// better but not optimal
int sumOfDivisorsofN(int n){
		int sum=0;
	for(int i=1;i*i<=n;i++){
		if(n%i==0)
		{
			sum+=i;
			if(i!=(n/i))
			sum+=(n/i);
		}
	}	
	return sum;
}
int sumOfAllDivisors1(int n){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=sumOfDivisorsofN(i);
	}
	return sum;
}

// optimal
int sumOfAllDivisors(int n){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=i*(n/i);
	}
	return sum;
}
int main(){
  
  
  
return 0;
}