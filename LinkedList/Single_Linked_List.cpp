#include <bits/stdc++.h>
using namespace std;
class Node
{ // user defined data structure
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1) // constructor 1
    {
        data = data1;
        next = next1;
    }
    Node(int data1) // constructor 2
    {
        data = data1;
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
int lengthOfLinkedList(Node *head)
{
    int count = 0;
    if (!head)
        return count;
    Node *curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}
bool search(Node *head, int val)
{
    if (!head)
        return false;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == val)
            return true;
        curr = curr->next;
    }
    return false;
}

// deletion related operations
Node *deleteAtBegin(Node *head)
{
    if (head == NULL) // if LL is empty
        return NULL;
    if (head->next == NULL) // if LL contains a single element
    {
        free(head);
        return NULL;
    }
    Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
Node *deleteAtEnd(Node *head)
{
    if (head == NULL) // if LL is empty
        return NULL;
    if (head->next == NULL) // if LL contains a single element
    {
        free(head);
        return NULL;
    }
    Node *ptr = head;
    Node *prev = NULL;
    while (ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    free(ptr);
    return head;
}
Node *deleteAtPosition(Node *head, int k)
{
    if (head == NULL) // if LL is empty
        return NULL;

    if (k == 1)
        return deleteAtBegin(head);
    Node *ptr = head;
    Node *prev = NULL;
    int count = 0;
    while (ptr->next != NULL)
    {
        count++;
        if (count == k)
            break;
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    free(ptr);
    return head;
}
Node *deleteByValue(Node *head, int val)
{
    if (head == NULL) // if LL is empty
        return NULL;

    if (head->data == val)
        return deleteAtBegin(head);
    Node *ptr = head;
    Node *prev = NULL;
    while (ptr->next != NULL)
    {
        if (ptr->data == val)
            break;
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    free(ptr);
    return head;
}

// Insert Related Operations
Node *insertAtBegin(Node *head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
    return head;
}
Node *insertAtEnd(Node *head, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return head;
}
Node *insertAtPosition(Node *head, int val, int k)
{
    if (k == 1 && head != NULL)
        return insertAtBegin(head, val);
    Node *ptr = head;
    int count = 0;
    while (ptr->next != NULL)
    {
        count++;
        if (count == k - 1)
            break;
        ptr = ptr->next;
    }
    Node *temp = new Node(val);
    temp->next=ptr->next;
    ptr->next = temp;
    return head;
}
Node *insertByValue(Node *head, int val, int target)
{
    if (head->data==target)
        return insertAtBegin(head, val);
    Node *ptr = head;
    Node *prev=NULL;
    while (ptr->next != NULL)
    {
        if (ptr->data==target)
            break;
        prev=ptr;
        ptr = ptr->next;
    }
    Node *temp = new Node(val);
    temp->next=ptr;
    prev->next = temp;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 10, 121, 12, 56, 23};
    Node *head = createLinkedList(arr);
    printLinkedList(head);
    cout << "Length of the Linked List: " << lengthOfLinkedList(head) << endl;
    // bool flag=search(head,17);
    // if(flag==true)
    // cout<<"Element is present";
    // else
    // cout<<"Element not present";
    // cout<<endl;
    // head=deleteAtBegin(head);
    // printLinkedList(head);
    // head = deleteAtEnd(head);
    // printLinkedList(head);
    // head = deleteAtPosition(head,4);
    // printLinkedList(head);
    // head = deleteByValue(head,121);
    // printLinkedList(head);
    // head = insertAtBegin(head, 54);
    // printLinkedList(head);
    // head = insertAtEnd(head, 5);
    // printLinkedList(head);
    // head=insertAtPosition(head,455,7);
    // printLinkedList(head);
    head=insertByValue(head,77,1);
    printLinkedList(head);
    return 0;
}