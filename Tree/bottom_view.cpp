#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
vector<int> bottomView(Node *root)
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

            mp[x] = curr->data;
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

int main()
{

    return 0;
}