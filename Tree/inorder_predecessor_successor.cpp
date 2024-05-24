#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *inorderPrdecessor(Node *root,int key){
    Node* pre=NULL;
    while(root){
        if(root->key >= key){
            root=root->left;
        }
        else{
            pre=root;
            root=root->right;
        }
    }
    return pre;
}

Node *inorderSuccessor(Node *root,int key){
    Node* suc=NULL;
    while(root){
        if(root->key <= key)
        root=root->right;
        else{
            suc=root;
            root=root->left;
        }
    }
    return suc;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
       pre=inorderPrdecessor(root,key);
       suc=inorderSuccessor(root,key);
}

// https://www.geeksforgeeks.org/problems/predecessor-and-successor/1
int main(){
  
  
  
return 0;
}