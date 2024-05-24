#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums2.size();
        unordered_map<int, int> nge;
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            int item = nums2[i];

            while (!st.empty() && item >= st.top())
                st.pop();

            if (!st.empty())
                nge[nums2[i]] = st.top();
            else
                nge[nums2[i]] =-1;

            st.push(nums2[i]);
        }
        vector<int> ans;
        for(auto it:nums1)
        {
            ans.push_back(nge[it]);
        }
        return ans;
    }
};
int main()
{
    Solution obj;
    vector<int> v{5, 7, 1, 2, 6, 0};
    vector<int> v1{5, 2, 6};
    vector<int> res = obj.nextGreaterElement(v, v1);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}

// https://leetcode.com/problems/next-greater-element-i/submissions/1192727224/