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

class Solution {
public:
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow=head,*fast=head;

        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        if(fast==NULL) // the head node should be deleted
        {
            head=head->next;
            free(slow);
            return head;
        }
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        ListNode *temp=slow->next;
        slow->next=slow->next->next;
        free(temp);
        return head;
    }
};
int main()
{

    return 0;
}

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/1185548802/