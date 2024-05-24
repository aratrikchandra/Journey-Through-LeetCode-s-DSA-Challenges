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

bool isBST(TreeNode* root,int lb,int ub){
        // edge case
        if(!root)
        return true;

        if(root->val <lb || root->val >ub)
        return false;

        return isBST(root->left,lb,root->val) && isBST(root->right,root->val,ub);
}
bool isValidBST(TreeNode* root) {
        return isBST(root,INT_MIN,INT_MAX);
    }

// https://leetcode.com/problems/validate-binary-search-tree/submissions/1244343701/
int main(){
  
  
  
return 0;
}