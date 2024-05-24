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
void flatten(TreeNode* root) {
        // using morris traversal
        TreeNode *curr=root;

        while(curr){
            if(curr->left==NULL){
                curr=curr->right;
            }
            else{
                TreeNode *pred=curr->left;

                while(pred->right)  // finding rightmost node in the left subtree
                pred=pred->right;

                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
                curr=curr->right;
            }
        }
    }

// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/1265609162/
int main(){
  
  
  
return 0;
}