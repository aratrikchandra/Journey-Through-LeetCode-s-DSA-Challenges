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

// preorder
void preorder(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    preorder(root, ans);
    return ans;
}
// https://leetcode.com/problems/binary-tree-preorder-traversal/
void inorder(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    inorder(root, ans);
    return ans;
}
// https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/1226659859/
void postorder(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    postorder(root, ans);
    return ans;
}
// https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/1226660967/
int main()
{

    return 0;
}