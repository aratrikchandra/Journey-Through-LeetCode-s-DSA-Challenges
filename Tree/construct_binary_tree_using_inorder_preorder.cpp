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
TreeNode *build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &inMap)
{
    // base case
    if (preStart > preEnd || inStart > inEnd) // invalid range for subtree
        return NULL;

    TreeNode *root = new TreeNode(preorder[preStart]);
    int rootIndex = inMap[root->val];

    int numsLeft=rootIndex-inStart; // number of elements in the left subtree

    root->left=build(preorder,preStart+1,preStart+numsLeft,inorder,inStart,rootIndex-1,inMap);
    root->right=build(preorder,preStart+numsLeft+1,preEnd,inorder,rootIndex+1,inEnd,inMap);

    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int n = preorder.size();

    // build the hash map
    unordered_map<int, int> inMap;
    for (int i = 0; i < n; i++)
    {
        inMap[inorder[i]] = i;
    }
    return build(preorder, 0, n - 1, inorder, 0, n - 1, inMap);
}
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/1264797362/
int main()
{

    return 0;
}