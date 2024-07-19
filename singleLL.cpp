#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    // constructor
    Node()
    {
        val = 0;
        next = NULL;
    }
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
Node *createLinkedList(vector<int> &arr)
{
    int n = arr.size();
    Node *head = NULL;
    if (n == 0)
        return head;

    head = new Node(arr[0]);
    Node *tail = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        tail->next = temp;
        tail = temp;
    }
    return head;
}
int lengthOfLinkedList(Node *head)
{
    Node *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}
void printLinkedList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
bool search(Node *head, int target)
{
    Node *ptr = head;
    while (ptr)
    {
        if (ptr->val == target)
            return true;
        ptr=ptr->next;
    }
    return false;
}
Node *deleteAtBegin(Node *head)
{
    Node *ptr = head;
    if (head->next == NULL)
    {
        head = NULL;
        return head;
    }
    head = head->next;
    delete ptr;
    return head;
}
Node *deleteAtEnd(Node *head)
{
    Node *ptr = head;
    if (head->next == NULL)
    {
        head = NULL;
        return head;
    }
    Node *q;
    while (ptr->next)
    {
        q = ptr;
        ptr = ptr->next;
    }
    q->next = NULL;
    delete ptr;
    return head;
}
Node *deleteAtPosition(Node *head, int k)
{
    int n = lengthOfLinkedList(head);
    if (k <= 0 || k > n)
        return head;
    if (k == 1)
        return deleteAtBegin(head);
    if (k == n)
        return deleteAtEnd(head);
    int count = 0;
    Node *ptr = head;
    Node *q;
    while (ptr)
    {
        count++;
        if (count == k)
        {
            q->next = ptr->next;
            delete ptr;
            break;
        }
        q = ptr;
        ptr = ptr->next;
    }
    return head;
}
// https://www.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1
Node *deleteByValue(Node *head, int target)
{
    Node *ptr = head;
    if (head->val == target)
        return deleteAtBegin(head);
    Node *q;
    while (ptr)
    {
        if (ptr->val == target)
        {
            break;
        }
        q = ptr;
        ptr = ptr->next;
    }
    q->next = ptr->next;
    delete ptr;
    return head;
}
Node *insertAtBegin(Node *head, int item)
{
    Node *temp = new Node(item);
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    temp->next = head;
    head = temp;
    return head;
}
Node *insertAtEnd(Node *head, int item)
{
    Node *temp = new Node(item);
    if(head==NULL){
        head=temp;
        return head;
    }
    Node *ptr = head;
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return head;
}
Node *insertAtPosition(Node *head, int item, int k)
{
    if (k == 1)
        return insertAtBegin(head, item);
    Node *temp = new Node(item);
    Node *ptr = head;
    int count = 0;
    while (ptr)
    {
        count++;
        if (count == k - 1)
        {
            temp->next = ptr->next;
            ptr->next = temp;
            break;
        }
        ptr = ptr->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 10, 121, 12, 56, 23};
    vector<int> arr2 = {1};
    Node *head = createLinkedList(arr);
    printLinkedList(head);
    // cout << "Length of the Linked List: " << lengthOfLinkedList(head) << endl;
    // bool flag=search(head,10);
    // if(flag==true)
    // cout<<"Element is present";
    // else
    // cout<<"Element not present";
    // cout<<endl;
    // head=deleteAtBegin(head);
    // printLinkedList(head);
    // head = deleteAtEnd(head);
    // printLinkedList(head);
    // head = deleteAtPosition(head,5);
    // printLinkedList(head);
    // head = deleteByValue(head,121);
    // printLinkedList(head);
    // head = insertAtBegin(head, 54);
    // printLinkedList(head);
    // head = insertAtEnd(head, 5);
    // printLinkedList(head);
    // head = insertAtPosition(head, 455, 7);
    // printLinkedList(head);
    return 0;
}