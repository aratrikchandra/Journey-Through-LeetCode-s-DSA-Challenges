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
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    // edge case
    if (!root)
    {
        TreeNode *node = new TreeNode(val);
        return node;
    }
    TreeNode *curr = root;
    while (curr)
    {
        if (curr->val > val) // move to left
        {
            if (curr->left) // if left child exists then that becomes our current node
            {
                curr = curr->left;
            }
            else  // if left child does not exist then make new node left child of current node and return
            {
                curr->left = new TreeNode(val);
                break;
            }
        }
        else if (curr->val < val) // move to right
        {
            if (curr->right) // if right child exists then that becomes our current node
            {
                curr = curr->right;
            }
            else  // if right child does not exist then make new node right child of current node and return
            {
                curr->right = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}

// https://leetcode.com/problems/insert-into-a-binary-search-tree/submissions/1244297850/
int main()
{

    return 0;
}