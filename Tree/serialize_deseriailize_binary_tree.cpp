#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ans = "";
        if (!root)
            return ans;

        // we will apply level order traversal
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node != NULL)
            {
                ans+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
            else{
                ans+="#,";
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if(data.empty())
        return NULL;

        stringstream s(data);

        string str;
        getline(s,str,',');
        TreeNode *root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            // left child
            getline(s,str,',');
            // if left child is indeed present
            if(str!="#")
            {
                TreeNode* leftChild=new TreeNode(stoi(str));
                node->left=leftChild;
                q.push(leftChild);
            }
            else{
                node->left=NULL;
            }

            // right child
            getline(s,str,',');
            // if right child is indeed present
            if(str!="#")
            {
                TreeNode* rightChild=new TreeNode(stoi(str));
                node->right=rightChild;
                q.push(rightChild);
            }else{
                node->right=NULL;
            }
        }
        return root;
    }
};
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/submissions/1261121276/
void inorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec solution;
    cout << "Orignal Tree: ";
    inorder(root);
    cout << endl;

    string serialized = solution.serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode *deserialized = solution.deserialize(serialized);
    cout << "Tree after deserialisation: ";
    inorder(deserialized);
    cout << endl;

    return 0;
}