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
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *curr = head;
        ListNode *last = NULL;
        ListNode *front = NULL;
        while (curr)
        {
            front = curr->next;
            curr->next = last;
            last = curr;
            curr = front;
        }
        return last;
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *slow=head,*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL) // generic condition for odd and even length list 
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *newHead=reverseList(slow->next);
        ListNode *first=head;
        ListNode *second=newHead;

        while(second!=NULL)
        {
            if(first->val!=second->val)
                return false;
            first=first->next;
            second=second->next;
        }
        newHead=reverseList(slow->next);
        return true;
    }
};
int main()
{

    return 0;
}

// https://leetcode.com/problems/palindrome-linked-list/submissions/1184230276/