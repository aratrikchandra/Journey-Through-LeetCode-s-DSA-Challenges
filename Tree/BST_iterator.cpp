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
class BSTIterator {
    private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode *node=st.top();
        st.pop();
        pushAllLeft(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushAllLeft(TreeNode *node){
        while(node!=NULL){
            st.push(node);
            node=node->left;
        }
    }
};
// https://leetcode.com/problems/binary-search-tree-iterator/submissions/1280672877/
int main(){
  
  
  
return 0;
}