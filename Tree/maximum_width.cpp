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

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
       // edge case
        if(!root)
        return 0;

        queue<pair<TreeNode*,long>> q;
        int ans=0;
        q.push({root,0});
        while(!q.empty())
        {
            int size=q.size();

            long mini=q.front().second;  // index of the left most node
            long first,last;

            for(int i=0;i<size;i++){
                TreeNode *node=q.front().first;
                long modified_index=q.front().second - mini;
                q.pop();
                // if current node is left-most
                if(i==0)
                first=modified_index;
                // if current node is right most
                if(i==size-1)
                last=modified_index;

                if(node->left)
                q.push({node->left,modified_index*2 +1});

                if(node->right)
                q.push({node->right,modified_index*2 +2});

            }
            // width of the current level
            int width=last-first+1;
            ans=max(ans,width);
        }

        return ans;
    }
};
int main(){
  
  
  
return 0;
}