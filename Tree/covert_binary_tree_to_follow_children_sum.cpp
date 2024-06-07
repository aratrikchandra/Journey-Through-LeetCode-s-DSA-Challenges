#include <bits/stdc++.h>
using namespace std;

    // Following is the Binary Tree node structure
    template<typename T>
    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

void changeTree(BinaryTreeNode < int > * root) {
   // base case
   if(!root)
   return;
    BinaryTreeNode < int > * left=root->left;
    BinaryTreeNode < int > * right=root->right;
    int sum=0;
    if(root->left)
    sum+=left->data;

    if(root->right)
    sum+=right->data;
    if(sum>=root->data){
        root->data=sum;
    }
    else{
    if(root->left)
    left->data=root->data;

    if(root->right)
    right->data=root->data; 
    }

    changeTree(root->left);
    changeTree(root->right);

    left=root->left;
    right=root->right;

    sum=0;
    if(root->left)
    sum+=left->data;

    if(root->right)
    sum+=right->data;
    if(sum>=root->data){
        root->data=sum;
    }
}  
// https://www.naukri.com/code360/problems/childrensumproperty_790723?leftPanelTabValue=SUBMISSION
int main(){
  
  
  
return 0;
}