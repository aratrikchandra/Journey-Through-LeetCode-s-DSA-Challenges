#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *findMiddleNode(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) // generic condition for odd and even length list
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *merge(ListNode *head1, ListNode *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    ListNode *dummyNode = new ListNode(-1);
    ListNode *curr = dummyNode;
    ListNode *ptr1 = head1;
    ListNode *ptr2 = head2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->val < ptr2->val)
        {
            curr->next = ptr1;
            curr = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            curr->next = ptr2;
            curr = ptr2;
            ptr2 = ptr2->next;
        }
    }

    if (ptr1 != NULL)
    {
        curr->next = ptr1;
    }
    else
    {
        curr->next = ptr2;
    }
    return dummyNode->next;
}
// recursive function
ListNode *mergeSort(ListNode *head)
{
    // base case
    if(head==NULL || head->next==NULL)
        return head;
    ListNode *mid=findMiddleNode(head);
    ListNode *left=head;
    ListNode *right=mid->next;
    mid->next=NULL;

    left=mergeSort(left);
    right=mergeSort(right);
    
    return merge(left,right);
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/sort-list/submissions/1189738892/