#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *right;
    struct Node *left;
};
int minValue(struct Node *root) {
    // your code here
    int mini=-1;
    while(root)
    {
        mini=root->data;
        root=root->left;
    }
    
    return mini;
}
// https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1
int main(){
  
  
  
return 0;
}