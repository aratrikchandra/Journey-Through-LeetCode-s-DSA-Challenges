#include <bits/stdc++.h>
using namespace std;
vector<int> prevSmaller(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> st;
    for (int i = 0; i <n; i++)
    {
        int item = arr[i];

        while (!st.empty() && item <= st.top())
            st.pop();

            if (!st.empty())
                nge[i] = st.top();

        st.push(arr[i]);
    }
    return nge;
}
int main()
{
    vector<int> v{5, 7, 1, 2, 6, 0};
    vector<int> res = prevSmaller(v);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}

// https://www.interviewbit.com/problems/nearest-smaller-element/