#include <bits/stdc++.h>
using namespace std;
class Node
{ // user defined data structure
public:
    int data;
    Node *prev;
    Node *next;

public:
    Node(int data1, Node *prev1, Node *next1) // constructor 1
    {
        data = data1;
        prev = prev1;
        next = next1;
    }
    Node(int data1) // constructor 2
    {
        data = data1;
        prev = nullptr;
        next = nullptr;
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
        ptr->next = temp;
        temp->prev = ptr;
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
        curr = curr->next;
    }
    cout << endl;
}

Node *removeDuplicates(Node *head)
{
    if(head==NULL || head->next==NULL)
    return head;

    Node *curr=head;
    while(curr!=NULL)
    {
        Node *nextNode=curr->next;
        while(nextNode !=NULL && nextNode->data==curr->data)
        {
            Node *temp=nextNode;
            nextNode=nextNode->next;
            free(temp);
        }
        curr->next=nextNode;
        if(nextNode)nextNode->prev=curr;
        curr=nextNode;
    }
    return head;
}
int main()
{
    vector<int> arr = {1, 1, 1, 2, 2, 2,3, 3, 4, 5};
    Node *head = createLinkedList(arr);
    printLinkedList(head);
    printLinkedList(removeDuplicates(head));
    return 0;
}

// https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1