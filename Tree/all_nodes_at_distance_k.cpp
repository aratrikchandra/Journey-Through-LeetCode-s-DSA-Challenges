#include <bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

void findingParent(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &parent){

    //BFS Traversal
    queue<TreeNode*> q;
    q.push(root);
    parent[root]=NULL;
    while(!q.empty()){
        TreeNode *node=q.front();
        q.pop();

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

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        // edge case
        if(!root)
            return ans;
        unordered_map<TreeNode*,TreeNode*> parent;
        findingParent(root,parent);

        queue<TreeNode*> q;
        unordered_map<TreeNode*, int> visited; // we should visit each node only once
        q.push(target); // start with target
        visited[target]=1;
        int distance =0;
        while(true){
            if(distance==k)
            break;

            distance++;
            int size=q.size();

            for(int i=0;i<size;i++){
                TreeNode *node=q.front();
                q.pop();

                // if left child exists and not visited previously
                if(node->left && visited[node->left]==0){
                    q.push(node->left);
                    visited[node->left]=1;
                }
                // if right child exists and not visited previously
                if(node->right && visited[node->right]==0){
                    q.push(node->right);
                    visited[node->right]=1;
                }

                if(parent[node] && visited[parent[node]]==0){
                    q.push(parent[node]);
                    visited[parent[node]]=1;
                }
            }
        }

        // elements present in the queue now are k distance elements
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        } 
        return ans;

    }

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
int main(){
  
  
  
return 0;
}