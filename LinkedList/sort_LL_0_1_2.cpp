#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *sortList(Node *head)
{

    if (head == NULL || head->next == NULL)
        return head;
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);

    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;

    Node *ptr = head;
    while (ptr != NULL)
    {
        switch (ptr->data)
        {
        case 0:
            zero->next = ptr;
            zero = ptr;
            zero->next = NULL;
            break;
        case 1:
            one->next = ptr;
            one = ptr;
            one->next = NULL;
            break;
        case 2:
            two->next = ptr;
            two = ptr;
            two->next = NULL;
            break;

        default:
            break;
        }
        ptr=ptr->next;
    }
    zero->next=(oneHead->next)?oneHead->next:twoHead->next;
    one->next=twoHead->next;
    two->next=NULL;
}
int main()
{

    return 0;
}

// https://www.codingninjas.com/studio/problems/sort-linked-list-of-0s-1s-2s_1071937?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION