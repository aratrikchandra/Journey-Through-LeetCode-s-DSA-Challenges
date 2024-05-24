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

int height(TreeNode *root){
    if(!root)
    return 0;

    int lh=height(root->left);
    if(lh==-1)
    return -1;
    int rh=height(root->right);
    if(rh==-1)
    return -1;

    // check the balanced condition
    if(abs(lh-rh)>1)
    return -1;

    return 1+ max(lh,rh);
}
bool isBalanced(TreeNode* root) {
        int h=height(root);
        if(h==-1)
        return false;

        return true;
    }

// https://leetcode.com/problems/balanced-binary-tree/submissions/1227847087/
int main(){
  
  
  
return 0;
}