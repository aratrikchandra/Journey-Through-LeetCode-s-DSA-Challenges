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
TreeNode *buildTree(vector<int> &preorder, int &i, int ub){
        // base case
        if(i==preorder.size())
        return NULL;

        // invalid range
        if(preorder[i]>ub)
        return NULL;

        TreeNode *node=new TreeNode(preorder[i]);
        i++;

        node->left=buildTree(preorder,i,node->val);
        node->right=buildTree(preorder,i,ub);

        return node;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int i=0; // to traverse the preorder array

    return buildTree(preorder,i,INT_MAX);
}

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/submissions/1265587519/
int main()
{

    return 0;
}