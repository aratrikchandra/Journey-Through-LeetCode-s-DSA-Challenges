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

TreeNode *inorderPredecessor(TreeNode *root)
{
    if(!root)
    return NULL;
    while(root->right){
        root=root->right;
    }
    return root;
}

TreeNode *adjust(TreeNode *root)
{
    // if one child is null return another
    if(root->left==NULL)
    return root->right;

    if(root->right==NULL)
    return root->left;

    // both left and right child exists
    TreeNode *rightChild=root->right;

    TreeNode *rightmostInLeftSubtree=inorderPredecessor(root->left);

    rightmostInLeftSubtree->right=rightChild;

    return root->left;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    // edge case 1
    if (!root)
        return NULL;
    // edge case 2
    if (root->val == key)
    { // we need to delete the root node
        root = adjust(root);
        return root;
    }
    TreeNode *curr = root;

    while (curr)
    {

        if (curr->val > key) // move to left
        {
            // if the left child is the node to be deleted
            if (curr->left && curr->left->val == key)
            {
                curr->left = adjust(curr->left);
                break;
            }
            else
                curr = curr->left;
        }
        else
        { // move to right

            // if right child is the node to be deleted
            if (curr->right && curr->right->val == key)
            {
                curr->right = adjust(curr->right);
                break;
            }
            else
                curr = curr->right;
        }
    }
    return root;
}
// https://leetcode.com/problems/delete-node-in-a-bst/submissions/1244331475/
int main()
{

    return 0;
}