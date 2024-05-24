#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
vector<int> topView(Node *root)
{
    vector<int> ans;
    // edge case
    if (root == NULL)
        return ans;

    map<int, int> mp;
    queue<pair<Node *, int>> q;

    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto it = q.front();
            int x = it.second;
            Node *curr = it.first;
            q.pop();

            if (mp.find(x) == mp.end())
            {
                // this is the first time we are encountering this vertical col
                mp[x] = curr->data;
            }
            if (curr->left)
            {
                q.push({curr->left, x - 1});
            }
            if (curr->right)
            {
                q.push({curr->right, x + 1});
            }
        }
    }

    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
int main()
{

    return 0;
}