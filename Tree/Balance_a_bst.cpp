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

void inorder(TreeNode *root, vector<int> &arr){
    if(!root)
    return;

    inorder(root->left,arr);
    arr.push_back(root->val);
    inorder(root->right,arr);
}

TreeNode *inorderToBST(int start, int end, vector<int> &arr){
        // base case
        if(start>end)
        return NULL;

        int mid=(start+end)/2;
        TreeNode *root=new TreeNode(arr[mid]);
        //left subtree
        root->left=inorderToBST(start,mid-1,arr);
        root->right=inorderToBST(mid+1,end,arr);

        return root;
}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);

        // convert inorder to balanced bst
        return inorderToBST(0,arr.size()-1,arr);
    }
// https://leetcode.com/problems/balance-a-binary-search-tree/submissions/1280700695/
int main(){
  
  
  
return 0;
}