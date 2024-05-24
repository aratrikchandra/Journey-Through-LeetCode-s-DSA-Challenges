#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
int floor(Node* root, int key) {
        int floor=-1;
        if(!root)
        return floor;

        Node *curr=root;
        while(curr){
            if(curr->data <key)
            {
                floor=curr->data;
                curr=curr->right;
            }
            else if(curr->data >key){
                curr=curr->left;
            }
            else{
                floor=curr->data;
                break;
            }
        }
        return floor;
    }

// https://www.geeksforgeeks.org/problems/floor-in-bst/1
int main(){
  
  
  
return 0;
}