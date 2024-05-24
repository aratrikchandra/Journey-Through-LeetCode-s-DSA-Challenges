
#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long val=1;
    for(int i=0;i<r;i++)
    {
        val=val*(n-i);
        val=val/(i+1);
    }
    return val;
}

int pascalTriangle(int r, int c) {
   int val=nCr(r-1,c-1);
   return val;
}

int main()
{
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: "
            << element << "\n";
    return 0;
}
        