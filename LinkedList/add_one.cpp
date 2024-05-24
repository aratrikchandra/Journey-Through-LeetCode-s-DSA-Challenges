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


Node* reverseList(Node* head) {
        if(head==NULL || head->next==NULL)
            return head;
        Node *curr=head;
        Node *last=NULL;
        Node *front=NULL;
        while(curr)
        {
            front=curr->next;
            curr->next=last;
            last=curr;
            curr=front;
        }
        return last;
    }

// iterative approach
Node *addOne1(Node *head)
{
    head=reverseList(head);
    int  carry=1;
    Node *ptr=head;
    while(ptr!=NULL)
    {
        int sum=ptr->data+carry;
        if(sum<10)
        {
            ptr->data=sum;
            carry=0;
            break;
        }
        else
        {
            ptr->data=0;
            carry=1;
        }
        ptr=ptr->next;
    }
    head=reverseList(head);
    if(carry==1)
    {
        Node *temp=new Node(carry);
        temp->next=head;
        head=temp;
    }
    return head;
}

// recursive approach

int recur(Node *ptr)
{
    if(ptr==NULL) // base case
        return 1;
    int carry=recur(ptr->next);
    int sum=ptr->data+carry;
        if(sum<10)
        {
            ptr->data=sum;
            carry=0;
        }
        else
        {
            ptr->data=0;
            carry=1;
        }
        return carry;
}
Node *addOne(Node *head){
    int carry=recur(head);
    if(carry==1)
    {
        Node *temp=new Node(carry);
        temp->next=head;
        head=temp;
    }
    return head;
}
int main()
{
    vector<int> arr = {1,4,5,7};
    Node *head = createLinkedList(arr);
    printLinkedList(head);
   printLinkedList(addOne(head));
    return 0;
}

// https://www.codingninjas.com/studio/problems/add-one-to-a-number-represented-as-linked-list_920557?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION