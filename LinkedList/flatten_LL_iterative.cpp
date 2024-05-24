#include <bits/stdc++.h>
using namespace std;
class Node
{ // user defined data structure
public:
    int data;
    Node *next;
    Node *child;

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
        child=nullptr;
    }
};

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
Node *merge(Node *head1,Node *head2)
{
 if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    Node *dummyNode=new Node(-1);
    Node *curr=dummyNode;
    Node *ptr1=head1;
    Node *ptr2=head2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->data<ptr2->data)
        {
            curr->child=ptr1;
            curr=ptr1;
            ptr1=ptr1->child;
        }
        else
        {
            curr->child=ptr2;
            curr=ptr2;
            ptr2=ptr2->child;
        }
        curr->next=NULL;
    }

    if(ptr1!=NULL)
    {
        curr->child=ptr1;
    }
    else
    {
        curr->child=ptr2;
    }
    return dummyNode->child;   
}

// iterative approach
Node* flattenLinkedList(Node* head) 
{
    	if(head==NULL || head->next==NULL) 
        return head;

        Node *ptr1=head;
        while(ptr1->next!=NULL)
        {
            Node *nextHead=ptr1->next->next;
            ptr1=merge(ptr1,ptr1->next);
            ptr1->next=nextHead;
        }
        return ptr1;
}
// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
int main(){
  
  
  
return 0;
}
