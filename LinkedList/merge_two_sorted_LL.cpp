#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

Node<int> *sortTwoLists(Node<int> *head1, Node<int> *head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    Node<int> *dummyNode=new Node(-1);
    Node<int> *curr=dummyNode;
    Node<int> *ptr1=head1;
    Node<int> *ptr2=head2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->data<ptr2->data)
        {
            curr->next=ptr1;
            curr=ptr1;
            ptr1=ptr1->next;
        }
        else
        {
            curr->next=ptr2;
            curr=ptr2;
            ptr2=ptr2->next;
        }
    }

    if(ptr1!=NULL)
    {
        curr->next=ptr1;
    }
    else
    {
        curr->next=ptr2;
    }
    return dummyNode->next;
}
int main()
{

    return 0;
}

// https://www.codingninjas.com/studio/problems/merge-two-sorted-linked-lists_800332?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=SUBMISSION