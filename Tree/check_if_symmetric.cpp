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
bool check(TreeNode *root1, TreeNode *root2){
    // base case
    if(!root1 || !root2)
    return root1==root2; // if both are null then return true otherwise false

    if(root1->val != root2->val)
    return false;

    return check(root1->left,root2->right) && check(root1->right,root2->left);
}
bool isSymmetric(TreeNode* root) {
     if(!root)
     return true;

     return check(root->left,root->right);   
}
// https://leetcode.com/problems/symmetric-tree/submissions/1228507731/
int main(){
  
  
  
return 0;
}