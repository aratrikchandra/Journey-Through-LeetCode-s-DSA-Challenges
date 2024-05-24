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
vector<int> inorderTraversal(TreeNode* root) {
     TreeNode *curr=root;
     vector<int> ans;
     while(curr!=NULL)
     {
        if(curr->left==NULL) // left subtree is empty
        {
            ans.push_back(curr->val); // print the current node
            curr=curr->right; // move to right subtree
        }
        else{
            TreeNode *predecessor = curr->left;
            while(predecessor->right && predecessor->right !=curr) // finding inorder predecessor of curr
            predecessor=predecessor->right;

            if(predecessor->right==NULL)  // visiting inorder predecessor for the first time
            {
                predecessor->right=curr; // creating the thread
                curr=curr->left; // move to left subtree of the current node

            }else{  // visiting inorder predecessor for the second time

                predecessor->right=NULL; // removing the thread
                ans.push_back(curr->val); // print the current node
                curr=curr->right; // move to right subtree
            }
        }
        
     }
     return ans;   
    }

// https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/1259507833/
int main(){
  
  
  
return 0;
}