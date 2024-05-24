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
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case 1
        if(!root)
        return NULL;
        // base case 2
        if(root==p || root==q)
        return root;

        TreeNode *leftChild=lowestCommonAncestor(root->left,p,q);
        TreeNode *rightChild=lowestCommonAncestor(root->right,p,q);

        if(leftChild==NULL && rightChild==NULL)
        return NULL;
        else if(leftChild==NULL)
        return rightChild;
        else if(rightChild==NULL)
        return leftChild;
        else{
            return root;
        }
    }
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/1228719793/
int main(){
  
  
  
return 0;
}