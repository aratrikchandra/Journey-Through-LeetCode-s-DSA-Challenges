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
// iterator to move from left to right
class BSTIteratorLeft {
    private:
    stack<TreeNode*> st;
public:
    BSTIteratorLeft(TreeNode* root) {
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
// iterator to move from right to left
class BSTIteratorRight {
    private:
    stack<TreeNode*> st;
public:
    BSTIteratorRight(TreeNode* root) {
        pushAllRight(root);
    }
    
    int before() {
        TreeNode *node=st.top();
        st.pop();
        pushAllRight(node->left);
        return node->val;
    }
    
    bool hasBefore() {
        return !st.empty();
    }

    void pushAllRight(TreeNode *node){
        while(node!=NULL){
            st.push(node);
            node=node->right;
        }
    }
};
    bool findTarget(TreeNode* root, int k) {
        if(!root)
        return false;

        BSTIteratorLeft left(root);
        BSTIteratorRight right(root);

        int i=left.next(); // smallest element in bst
        int j=right.before(); // largest element in bst

        while(i<j){
            if(i+j<k){
                i=left.next();
            }
            else if(i+j>k)
            {
                j=right.before();
            }
            else
                return true;
        }

        return false;
    }
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/1280688216/
int main(){
  
  
  
return 0;
}