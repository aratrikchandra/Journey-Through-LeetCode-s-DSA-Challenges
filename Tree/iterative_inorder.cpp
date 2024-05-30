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
        vector<int> ans;
        if(!root)
        return ans;
       stack<TreeNode*> st;
       TreeNode *curr=root;


       while(true){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        else{
            if(st.empty())
            break;

            TreeNode *node=st.top();
            st.pop();

            ans.push_back(node->val);
            curr=node->right;
            
        }
       }
       return ans;
    }
// https://leetcode.com/problems/binary-tree-inorder-traversal/
int main(){
  
  
  
return 0;
}