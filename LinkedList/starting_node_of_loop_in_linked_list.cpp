#include <bits/stdc++.h>
using namespace std;
class ListNode
{ // user defined data structure
public:
    int data;
    ListNode *next;

public:
    ListNode(int data1, ListNode *next1) // constructor 1
    {
        data = data1;
        next = next1;
    }
    ListNode(int data1) // constructor 2
    {
        data = data1;
        next = nullptr;
    }
};
ListNode *findStartingListNode(ListNode *slow, ListNode *fast)
{
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
 ListNode *detectCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL && fast->next->next !=NULL) // generic condition for odd and even length list
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return findStartingListNode(head,fast);
        }
    }
    return NULL;
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/linked-list-cycle-ii/submissions/1184879062/