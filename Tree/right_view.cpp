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

void solve(TreeNode *root,int level,vector<int> &ans){
    // base case
    if(!root)
    return;

    // reverse post order
    if(ans.size()==level) // this is the first node in this level form right
    {
        ans.push_back(root->val);
    }
    solve(root->right,level+1,ans);
    solve(root->left,level+1,ans);
}
vector<int> rightSideView(TreeNode* root) {
        int level=0;
        vector<int> ans;
        // edge case
        if(!root)
        return ans;
        solve(root,level,ans);

        return ans;
    }

// https://leetcode.com/problems/binary-tree-right-side-view/submissions/1228511643/
int main(){
  
  
  
return 0;
}