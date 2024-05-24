#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;

    // constructor
    Node(int data){
        this->data=data;
    }
};
int main(){
     // Creating a new node by using dynamic allocation.
    Node* root = new Node(1);
   root -> left = new Node(2);
   root -> right = new Node(3);
   root -> left -> right = new Node(5);
return 0;
}