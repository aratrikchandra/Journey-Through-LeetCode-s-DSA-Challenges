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
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
           vector<vector<int>> ans;
        // edge case
        if(root==NULL)
        return ans;
        bool flag=true; // true means left to right
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> ds(size,0);
            for(int i=0;i<size;i++){
                TreeNode *node=q.front();
                q.pop();
                if(flag){
                    ds[i]=node->val;
                }
                else{
                    ds[size-i-1]=node->val;
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            flag=!flag;
            ans.push_back(ds);
        }
        return ans;
    }
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/1226947637/
int main(){
  
  
  
return 0;
}