#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void inorder(TreeNode *root, vector<int> &arr)
{
    if (!root)
        return;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

TreeNode *inorderToBST(int start, int end, vector<int> &arr)
{
    // base case
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    TreeNode *root = new TreeNode(arr[mid]);
    // left subtree
    root->left = inorderToBST(start, mid - 1, arr);
    root->right = inorderToBST(mid + 1, end, arr);

    return root;
}
vector<int> mergeTwoSortedArrays(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    int i = 0, j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else
        {
            ans.push_back(arr2[j]);
            j++;
        }
    }

    while (i < n)
    {
        ans.push_back(arr1[i]);
        i++;
    }

    while (j < m)
    {
        ans.push_back(arr2[j]);
        j++;
    }

    return ans;
}
TreeNode* mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> arr1, arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);

    vector<int> ans=mergeTwoSortedArrays(arr1,arr2);

    return inorderToBST(0,ans.size()-1, ans);
}
// https://www.naukri.com/code360/problems/h_920474?leftPanelTabValue=SUBMISSION
int main()
{

    return 0;
}