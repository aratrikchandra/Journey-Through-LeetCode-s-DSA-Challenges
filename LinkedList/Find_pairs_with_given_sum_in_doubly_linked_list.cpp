#include <bits/stdc++.h>
using namespace std;
class Node
{ // user defined data structure
public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int data1, Node *left1, Node *right1) // constructor 1
    {
        data = data1;
        left = left1;
        right = right1;
    }
    Node(int data1) // constructor 2
    {
        data = data1;
        left = nullptr;
        right = nullptr;
    }
};

Node *createLinkedList(vector<int> &arr)
{
    Node *head = NULL;
    int n = arr.size();
    if (n == 0)
        return head;
    head = new Node(arr[0]);
    Node *ptr = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        ptr->right = temp;
        temp->left = ptr;
        ptr = temp;
    }
    return head;
}
void printLinkedList(Node *head)
{
    if (!head)
        return;
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

Node *findTail(Node *head)
{
    Node *ptr = head;
    while (ptr->right != NULL)
    {
        ptr = ptr->right;
    }
    return ptr;
}
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> ans;
    if (head == NULL || head->right == NULL)
        return ans;
    Node *right = findTail(head);
    Node *left = head;
    while (left->data<right->data) // stopping condition is when left->data is greater then right->data
    {
        int val = left->data + right->data;
        if (val < target)
        {
            left = left->right;
        }
        else if (val > target)
        {
            right = right->left;
        }
        else
        {
            ans.push_back(make_pair(left->data,right->data));
            left = left->right;
            right = right->left;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4,5};
    Node *head = createLinkedList(arr);
    printLinkedList(head);
    int target=6;
    vector<pair<int, int>> ans=findPairsWithGivenSum(head,target);
    for(auto it: ans)
    {
        cout<<it.first<<","<<it.second<<endl;
    }
    return 0;
}



// https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1