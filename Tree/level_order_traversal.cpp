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
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        // edge case
        if(root==NULL)
        return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> ds;
            for(int i=0;i<size;i++){
                TreeNode *node=q.front();
                q.pop();
                ds.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(ds);
        }
        return ans;
    }

// https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/1226939311/
int main(){
  
  
  
return 0;
}