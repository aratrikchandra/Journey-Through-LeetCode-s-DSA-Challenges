\
#include <bits/stdc++.h>
using namespace std;

vector<int> pascalTriangle(int n) {
    vector<int> ans;

    long long prev=1;
    // we will total have n elements in row n
    ans.push_back(1);

    for(int i=1;i<n;i++)
    {
        prev= prev * (n-i);
        prev=prev/i;
        ans.push_back(prev);
    }
    return ans;
}

int main()
{
    int n = 6;
    vector<int> ans= pascalTriangle(n);
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
    return 0;
}
