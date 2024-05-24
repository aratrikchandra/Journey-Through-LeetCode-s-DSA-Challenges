
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Define a Node class for doubly linked list
class Node
{
public:
    // Data stored in the node
    int data;
    // Pointer to the next node in the list
    //(forward direction)
    Node *next;
    // Pointer to the previous node in the list
    //(backward direction)
    Node *back;

    // Constructor for a Node with both data,
    // a reference to the next node,
    // and a reference to the previous node
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor for a Node with data,
    // and no references to the next and
    // backious nodes (end of the list)
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array
// to a doubly linked list
Node *convertArr2DLL(vector<int> arr)
{
    // Create the head node with
    // the first element of the array

    Node *head = new Node(arr[0]);

    // Initialize 'prev' to the head node
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        // Create a new node with data from the
        // array and set its 'back' pointer to
        // the previous node

        Node *temp = new Node(arr[i], nullptr, prev);
        // Update the 'next' pointer of the
        // previous node to point to
        // the new node
        prev->next = temp;
        // Move 'prev' to the newly created
        // node for the next iteration
        prev = temp;
    }
    // Return the head of the doubly linked list
    return head;
}

// Function to print the elements
// of the doubly linked list
void print(Node *head)
{
    while (head != nullptr)
    {
        // Print the data in the tail node
        cout << head->data << " ";
        // Move to the next node
        head = head->next;
    }
}

// Function to reverse a doubly linked list
// In-place link exchange method
Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *curr=head;
    Node *last=NULL;
    Node *front=NULL;

    while(curr!=NULL)
    {
        last=curr->back;
        front=curr->next;
        curr->next=last;
        curr->back=front;
        last=curr;
        curr=front;
    }
    return last;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7, 4};
    Node *head = convertArr2DLL(arr);
    cout << endl
         << "Doubly Linked List Initially:  " << endl;
    print(head);
    cout << endl
         << "Doubly Linked List After Reversing " << endl;

    // Insert a node with value 10 at the end
    head = reverseDLL(head);
    print(head);

    return 0;
}

// https://www.codingninjas.com/studio/problems/reverse-a-doubly-linked-list_1116098?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION