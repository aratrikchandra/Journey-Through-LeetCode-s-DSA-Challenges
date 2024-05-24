#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    // edge case
    if (!root)
        return ans;
    map<int, map<int, multiset<int>>> mp;      //<vertical,<level,value>>
    queue<pair<TreeNode *, pair<int, int>>> q; // <node,<vertical,level>>
    // push the root and its co-ordinate
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto it = q.front();
            q.pop();
            TreeNode *node = it.first;
            int x = it.second.first;  // vertical col no.
            int y = it.second.second; // level no.

            mp[x][y].insert(node->val); // insert element in the map
            if (node->left)
            {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right)
            {
                q.push({node->right, {x + 1, y + 1}});
            }
        }
    }

    for(auto v:mp){
        vector<int> col;
        for(auto l:v.second){
            col.insert(col.end(),l.second.begin(),l.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/1227743713/
int main()
{

    return 0;
}