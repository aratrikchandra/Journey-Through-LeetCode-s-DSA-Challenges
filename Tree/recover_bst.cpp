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
    private:
    TreeNode *first, *middle, *last, *prev;
public:
    void inorder(TreeNode *root){

        // base case
        if(!root)
        return;

        inorder(root->left);
        // visiting the current node
        if(root->val < prev->val){
            // violation happened

            if(first==NULL) // first time violation
            {
                first=prev;
                middle=root;
            }
            else{
                // second time violation
                last=root;
            }
        }
        prev=root; // update prev after visiting the node
        
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=NULL;
        middle=NULL;
        last= NULL;

        prev= new TreeNode(INT_MIN);

        inorder(root);

        
        if(first && last){
            // if swapped nodes are not adjacent
            swap(first->val, last->val);
        }
        else if(first && middle){
            // if swapped nodes are adjacent
            swap(first->val, middle->val);
        }
    }
};

// https://leetcode.com/problems/recover-binary-search-tree/submissions/1260369234/
// Utility function to
// insert nodes into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Utility function to perform
// inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Function to swap two tree
// nodes and their subtrees
void swapNodes(TreeNode* a, TreeNode* b) {
    // Swap values of the nodes
    int temp = a->val;
    a->val = b->val;
    b->val = temp;

    // Swap left subtrees of the nodes
    TreeNode* tempLeft = a->left;
    a->left = b->left;
    b->left = tempLeft;

    // Swap right subtrees of the nodes
    TreeNode* tempRight = a->right;
    a->right = b->right;
    b->right = tempRight;
}

int main(){
  Solution solution;

    // Create the BST
    TreeNode* root = nullptr;
    root = insert(root, 3);
    insert(root, 1);
    insert(root, 4);
    insert(root, 2);

    cout << "Original BST: ";
    inorderTraversal(root);
    cout << endl;


    // Intentionally swapping two nodes (4 and 2) 
    TreeNode* node4 = root->right;
    TreeNode* node2 = root->left->right;
    swapNodes(node4, node2);
    
    cout << "BST with swapped nodes: ";
    inorderTraversal(root);
    cout << endl;
    
    // Recover the BST
    solution.recoverTree(root);
    
    cout << "Recovered BST: ";
    inorderTraversal(root);
    cout << endl;
  
  
return 0;
}