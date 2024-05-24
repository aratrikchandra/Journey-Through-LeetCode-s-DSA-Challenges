#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k)
{
    int n = num.size();
    // edge case
    if (k == n)
        return "0";
    stack<char> st;
    string ans="";
    for (int i = 0; i < n; i++)
    {
        while (k > 0 && !st.empty() && st.top() > num[i])
        {
            st.pop();
            k--;
        }

        st.push(num[i]);
    }
    while(k>0)
    {
        st.pop();
        k--;
    }
    while(!st.empty())
    {
        ans=st.top() + ans;
        st.pop();
    }
    int i=0;
    n=ans.size();
    while(i<n && ans[i]=='0')
    {
        i++;
    }
    ans.erase(ans.begin(),ans.begin()+i);
    return ans.empty()?"0":ans;
}
int main()
{
    string num = "001432219";
    int k = 3;
    cout<<removeKdigits(num,k);
    return 0;
}

// https://www.codingninjas.com/studio/problems/remove-k-digits_1461221?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION

// https://leetcode.com/problems/remove-k-digits/submissions/1194749724/

// use push_back function on string and then reverse instead of ans=character+ans for avoiding memory limit exceeded