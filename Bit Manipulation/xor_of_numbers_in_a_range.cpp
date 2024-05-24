#include <bits/stdc++.h>
using namespace std;
int xorUptoN(int n){
    switch(n%4){
        case 0:
            return n;
        case 1:
            return 1;
        case 2:
            return n+1;
        case 3:
            return 0;
    }
}
int findXOR(int L, int R){
    return xorUptoN(L-1)^xorUptoN(R);
}
int main(){
  
  
  
return 0;
}