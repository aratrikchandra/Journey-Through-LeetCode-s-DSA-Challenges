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

class Solution {
public:

// Important Note
// The issue of runtime error arises if we return when count becomes equal to k, because the return statements are terminating the function prematurely while the Morris Inorder Traversal threads are still in place. This causes inconsistencies when the traversal resumes from a different call stack frame. To address this, you need to ensure that all threads are properly dismantled before the function exits.

// To avoid the stack overflow issue, you should let the Morris Inorder Traversal complete its work, even after finding the k-th smallest element, so that all temporary threads are correctly removed.


    int kthSmallest(TreeNode* root, int k) {  // using morris inorder traversal
        TreeNode *curr = root;
        int count = 0;
        int ksmall = INT_MIN;
        while (curr) {
            if (curr->left == NULL) {
                count++;
                if (count == k)
                    ksmall = curr->val;
                curr = curr->right;
            } else {
                TreeNode *temp = curr->left;
                while (temp->right != NULL && temp->right != curr) {
                    temp = temp->right;
                }
                if (temp->right != NULL) {
                    temp->right = NULL;
                    count++;
                    if (count == k)
                        ksmall = curr->val;
                    curr = curr->right;
                } else {
                    temp->right = curr;
                    curr = curr->left;
                }
            }
        }
        return ksmall;
    }
};
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/1260294357/
int main()
{

  return 0;
}