#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;

  Node(int x)
  {
    data = x;
    left = right = NULL;
  }
};

class Solution
{
public:
  // Function to check whether all nodes of a tree have the dataue
  // equal to the sum of their child nodes.
  int isSumProperty(Node *root)
  {
    // base case for Null node
    if (!root)
      return 1;
    // Base case for leaf node
    if (root->left == NULL && root->right == NULL)
    {
      return 1;
    }
    if (isSumProperty(root->left) == 0)
      return 0;

    if (isSumProperty(root->right) == 0)
      return 0;

    int sum = 0;
    if (root->left)
      sum += root->left->data;

    if (root->right)
      sum += root->right->data;
    if (sum == root->data)
    {
      return 1;
    }
    return 0;
  }
};
// https://www.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=hildren-sum-parent
int main()
{

  return 0;
}