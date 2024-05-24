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
int height_sum(TreeNode *root, int &maxSum)
{
    if (!root)
        return 0;

    int leftSum = height_sum(root->left, maxSum);
    // we don't consider negative sum
    if (leftSum < 0)
        leftSum = 0;
    int rightSum = height_sum(root->right, maxSum);
    // we don't consider negative sum
    if (rightSum < 0)
        rightSum = 0;

    int currSum = root->val + leftSum + rightSum;

    maxSum = max(maxSum, currSum);

    return root->val + max(leftSum, rightSum);
}
int maxPathSum(TreeNode *root)
{
    int maxSum = INT_MIN;
    height_sum(root, maxSum);
    return maxSum;
}

// https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/1227865076/
int main()
{

    return 0;
}