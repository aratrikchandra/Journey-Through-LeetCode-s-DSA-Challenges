

#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> arr, int n)
{
    long long X;
    long long Y;

    long long Sn = n * (n + 1) / 2;
    long long S2n = n * (n + 1) * (2 * n + 1) / 6;

    long long S = 0;
    long long S2 = 0;

    for (int i = 0; i < n; i++)
    {
        S = S + (long long)arr[i];
        S2 = S2 + ((long long)arr[i] * (long long)arr[i]);
    }

    long long val1=S-Sn;  //val1 represnts X-Y
    long long val2=S2-S2n;
    val2=val2/val1; // val2 represnts X+Y

    X=(val1+val2)/2;
    Y=X-val1;

    return {int(X),int(Y)};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a, a.size());
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}

// https://www.codingninjas.com/studio/problems/missing-and-repeating-numbers_6828164?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTabValue=SUBMISSION

// check why gfg code not working

// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1