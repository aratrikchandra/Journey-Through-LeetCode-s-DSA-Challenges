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

bool dfs(TreeNode* root, int target,vector<int> &ans){
    // base case
    if(!root)
    return false;
    if(root->val==target)
    {
        ans.push_back(target);
        return true;
    }

    // adding current node into the path
    ans.push_back(root->val);

    if(dfs(root->left,target,ans)==true)
    return true;

    if(dfs(root->right,target,ans)==true)
    return true;

    // if current node not part of the actual path
    ans.pop_back();

    return false;
}
vector<int> rootToNode(TreeNode* A, int B) {
    vector<int> ans;
    // edge case
    if(A==NULL)
    return ans;
    dfs(A,B,ans);
    return ans;
}
// https://www.interviewbit.com/problems/path-to-given-node/
int main(){
  
  
  
return 0;
}