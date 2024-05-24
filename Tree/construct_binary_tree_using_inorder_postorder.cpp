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
TreeNode *build(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &inMap)
{
    // base case
    if (postStart > postEnd || inStart > inEnd) // invalid range for subtree
        return NULL;

    TreeNode *root = new TreeNode(postorder[postEnd]);
    int rootIndex = inMap[root->val];

    int numsLeft=rootIndex-inStart; // number of elements in the left subtree

    root->left=build(postorder,postStart,postStart+numsLeft-1,inorder,inStart,rootIndex-1,inMap);
    root->right=build(postorder,postStart+numsLeft,postEnd-1,inorder,rootIndex+1,inEnd,inMap);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = postorder.size();

    // build the hash map
    unordered_map<int, int> inMap;
    for (int i = 0; i < n; i++)
    {
        inMap[inorder[i]] = i;
    }
    return build(postorder, 0, n - 1, inorder, 0, n - 1, inMap);
    }

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/1264807873/
int main(){
  
  
  
return 0;
}