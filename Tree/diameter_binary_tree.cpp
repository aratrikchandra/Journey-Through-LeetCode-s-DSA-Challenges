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
  int height(TreeNode *root,int &maxDiameter){
    if(!root)
    return 0;

    int lh=height(root->left,maxDiameter);
    int rh=height(root->right,maxDiameter);

    int currDiameter=lh+rh;

    maxDiameter=max(maxDiameter,currDiameter);

    return 1+ max(lh,rh);
}
int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter=0;
        height(root,maxDiameter);
        return maxDiameter;
}
// https://leetcode.com/problems/diameter-of-binary-tree/
int main(){
  
  
  
return 0;
}