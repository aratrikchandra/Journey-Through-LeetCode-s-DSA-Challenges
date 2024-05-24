#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class NodeValue{
    public:
    int min_val;
    int max_val;
    int max_size;

    // constructor
    NodeValue(int min_val, int max_val, int max_size){
        this->min_val=min_val;
        this->max_val=max_val;
        this->max_size=max_size;
    }
};

class Solution{
    public:
    NodeValue findMaxBST(Node *root){
        // base case
        if(!root)
        return NodeValue(INT_MAX,INT_MIN,0);

        NodeValue leftChild= findMaxBST(root->left);
        NodeValue rightChild= findMaxBST(root->right);

        // check the validity condition
        if(root->data > leftChild.max_val && root->data < rightChild.min_val)
        {
            return NodeValue(min(root->data,leftChild.min_val),max(root->data,rightChild.max_val),1+ leftChild.max_size+rightChild.max_size);
        }
        
        // invalid case
        return NodeValue(INT_MIN,INT_MAX,max(leftChild.max_size, rightChild.max_size));
    }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	NodeValue ans=findMaxBST(root);

        return ans.max_size;
    }
};

// https://www.geeksforgeeks.org/problems/largest-bst/1
int main(){
  
  
  
return 0;
}