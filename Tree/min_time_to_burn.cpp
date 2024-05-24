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
void findingParent(Node *root,unordered_map<Node*,Node*> &parent,Node* src,int target){

    //BFS Traversal
    queue<Node*> q;
    q.push(root);
    parent[root]=NULL;
    while(!q.empty()){
        Node *node=q.front();
        q.pop();
        if(node->data==target)
        src=node;
        if(node->left)
        {
            parent[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            parent[node->right]=node;
            q.push(node->right);
        }
    }
}
 int minTime(Node* root, int target) 
    {
        // edge case
        if(!root)
        return 0;
        unordered_map<Node*,Node*> parent;
        Node *src=NULL;
        findingParent(root,parent,src,target);

        queue<Node*> q;
        unordered_map<Node*,int> visited;
        q.push(src); 
        visited[src]=1;

        int timer=0;
        bool flag=false;
        while(!q.empty()){
            int size=q.size();
            flag=false;
            for(int i=0;i<size;i++){
                Node *node=q.front();
                q.pop();

                if(node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left]=1;
                    flag=true;
                }

                if(node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right]=1;
                    flag=true;
                }

                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]];
                    flag=true;
                }
            }
            if(flag)
            timer++;
        }
        return timer;
    }

// https://www.geeksforgeeks.org/problems/burning-tree/1
int main(){
  
  
  
return 0;
}