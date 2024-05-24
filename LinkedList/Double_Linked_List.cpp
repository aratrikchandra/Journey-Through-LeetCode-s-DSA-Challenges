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
void printReverseLinkedList(Node *head)
{
    if (!head)
        return;
    Node *curr = head;
    while (curr->right != NULL)
    {
        curr = curr->right;
    }
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->left;
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
        curr = curr->right;
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
        curr = curr->right;
    }
    return false;
}

// deletion related operations
Node *deleteAtBegin(Node *head)
{
    if (head == NULL) // if LL is empty
        return NULL;
    if (head->right == NULL) // if LL contains a single element
    {
        free(head);
        return NULL;
    }
    Node *ptr = head;
    head = head->right;
    head->left = NULL;
    ptr->right = NULL;
    free(ptr);
    return head;
}
Node *deleteAtEnd(Node *head)
{
    if (head == NULL) // if LL is empty
        return NULL;
    if (head->right == NULL) // if LL contains a single element
    {
        free(head);
        return NULL;
    }
    Node *ptr = head;
    while (ptr->right != NULL)
    {
        ptr = ptr->right;
    }
    ptr->left->right = NULL;
    ptr->left = NULL;
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
    Node *next = NULL;
    int count = 0;
    while (ptr->right != NULL)
    {
        count++;
        if (count == k)
            break;
        prev = ptr;
        ptr = ptr->right;
    }
    next = ptr->right;
    if (next == NULL) // means kth element is the last element of the linked list
    {
        prev->right = NULL;
        ptr->left = NULL;
        free(ptr);
        return head;
    }
    prev->right = next;
    next->left = prev;
    ptr->left = NULL;
    ptr->right == NULL;
    free(ptr);
    return head;
}
// address of the node(to be deleted) is given
void deleteByNode(Node *ptr) // (it is guaranteed not to be the head)
{
    Node *prev = ptr->left;
    Node *next = ptr->right;
    if (next == NULL) // delete the last element of the linked list which is ptr
    {
        prev->right = NULL;
        ptr->left = NULL;
        free(ptr);
        return;
    }
    prev->right = next;
    next->left = prev;
    ptr->left = NULL;
    ptr->right == NULL;
    free(ptr);
}

// Insert Related Operations
Node *insertBeforeBegin(Node *head, int val)
{
    Node *temp = new Node(val);
    if(head==NULL)
    {
        return temp;
    }
    temp->right = head;
    head->left = temp;
    head = temp;
    return head;
}
Node *insertBeforeEnd(Node *head, int val)
{
    Node *temp = new Node(val);
    if (head == NULL) // if LL is empty
    {
        head = temp;
        return head;
    }
    if (head->right == NULL) // LL has only one element
        return insertBeforeBegin(head, val);

    Node *ptr = head;
    Node *prev = NULL;
    while (ptr->right != NULL)
    {
        ptr = ptr->right;
    }
    prev = ptr->left;
    temp->right = ptr;
    ptr->left = temp;
    prev->right = temp;
    temp->left = prev;
    return head;
}
Node *insertBeforePosition(Node *head, int val, int k) // linked list should be non empty
{
    if (k == 1 && head != NULL)
        return insertBeforeBegin(head, val);

    Node *ptr = head;
    Node *prev=NULL;
    int count = 0;
    while (ptr->right != NULL)
    {
        count++;
        if (count == k)
            break;
        ptr = ptr->right;
    }
    Node *temp = new Node(val);
    prev = ptr->left;
    temp->right = ptr;
    ptr->left = temp;
    prev->right = temp;
    temp->left = prev;
    return head;
}
void insertBeforeNode(Node *ptr, int val)   // linked list should be non empty
{
    //  It is guaranteed that the node will not be the head
    Node *prev = ptr->left;
    Node *temp = new Node(val);
    prev = ptr->left;
    temp->right = ptr;
    ptr->left = temp;
    prev->right = temp;
    temp->left = prev;
}
Node *insertAfterEnd(Node*head,int val)
{
    Node *temp = new Node(val);
    if (head == NULL)  // if LL is empty
    {
        head = temp;
        return head;
    }
    Node *ptr = head;
    while (ptr->right != NULL)
    {
        ptr = ptr->right;
    }
    ptr->right = temp;
    temp->left=ptr;
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 10, 121, 12, 56, 23};
    Node *head = createLinkedList(arr);
    printLinkedList(head);
    // printReverseLinkedList(head);
    cout << "Length of the Linked List: " << lengthOfLinkedList(head) << endl;
    // bool flag=search(head,17);
    // if(flag==true)
    // cout<<"Element is present";
    // else
    // cout<<"Element not present";
    // cout<<endl;
    head=deleteAtBegin(head);
    printLinkedList(head);
    head = deleteAtEnd(head);
    printLinkedList(head);
    head = deleteAtPosition(head,9);
    printLinkedList(head);
    Node *ptr=head->right->right->right->right;
    deleteByNode(ptr);
    printLinkedList(head);

    // head = insertBeforeBegin(head, 54);
    // printLinkedList(head);
    // head = insertBeforeEnd(head, 5);
    // printLinkedList(head);
    // head=insertBeforePosition(head,455,7);
    // printLinkedList(head);
    // Node *ptr=head->right->right->right->right;
    // insertBeforeNode(ptr,17);
    // printLinkedList(head);
    return 0;
}