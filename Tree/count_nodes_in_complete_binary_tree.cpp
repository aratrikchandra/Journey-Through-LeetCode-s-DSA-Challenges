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

int leftDepth(TreeNode *root)
{
    int depth = 0;

    while (root)
    {
        depth++;
        root = root->left;
    }
    return depth;
}
int rightDepth(TreeNode *root)
{
    int depth = 0;

    while (root)
    {
        depth++;
        root = root->right;
    }
    return depth;
}
int countNodes(TreeNode *root)
{
    // base case
    if (!root)
        return 0;

    int l_depth = leftDepth(root);
    int r_depth = rightDepth(root);

    if (l_depth == r_depth)
        return (1 << l_depth) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// https://leetcode.com/problems/count-complete-tree-nodes/
int main()
{

    return 0;
}