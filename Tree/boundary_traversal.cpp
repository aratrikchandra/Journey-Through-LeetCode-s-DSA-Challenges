#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
};
// have to make some edge case checks
    bool isLeaf(Node *root){
    return !root->left && !root->right;
}
void leftBoundary(Node *root,vector<int> &ans){
    if(!root || isLeaf(root))
    return;
    Node *curr=root;
    while(curr){
        if(!isLeaf(curr))
        ans.push_back(curr->data);
        if(curr->left){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
}
void botomBoundary(Node *root,vector<int> &ans){
    if(root==NULL)
    return;
    // pre order traversal
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }

    botomBoundary(root->left,ans);
    botomBoundary(root->right,ans);
}
void rightBoundary(Node *root,vector<int> &ans){
    
    if(!root || isLeaf(root))
    return;
    Node *curr=root;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr))
        temp.push_back(curr->data);
        if(curr->right){
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
    for(int i=temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
}
vector <int> boundary(Node *root)
{
    vector<int> ans;
    if(root==NULL)
    return ans;
    if(!isLeaf(root))
    ans.push_back(root->data);
    leftBoundary(root->left,ans);
    botomBoundary(root,ans);
    rightBoundary(root->right,ans);
    return ans;
}
// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
int main(){
  
  
  
return 0;
}