#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int findCeil(Node* root, int key) {
    if (root == NULL) 
        return -1;
    int ceil=-1;
    Node *curr=root;
    while(curr){
        if(curr->data== key)
        {
            ceil=curr->data;
            break;
        }
        else if(curr->data<key){
            curr=curr->right;
        }
        else{
            ceil=curr->data;
            curr=curr->left;
        }
    }
    return ceil;
}
// https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
int main(){
  
  
  
return 0;
}