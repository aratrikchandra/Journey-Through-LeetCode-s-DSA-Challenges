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
    // sol 1 using third pointer
    ListNode* delteMiddleNode1(ListNode* head) {
        if (head == NULL || head->next == NULL){
            if(!head)
                free(head);
            return NULL;
        }
            
        ListNode *slow=head,*fast=head;
        ListNode *prev=NULL;
        while(fast!=NULL && fast->next!=NULL) // generic condition for odd and even length list 
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        slow->next=NULL;
        free(slow);
        return head;
    }
    // sol2 without using third pointer
        ListNode* delteMiddleNode(ListNode* head) {
        if (head == NULL || head->next == NULL){
            if(!head)
                free(head);
            return NULL;
        }
            
        ListNode *slow=head,*fast=head;
        fast=fast->next->next;
        while(fast!=NULL && fast->next!=NULL) // generic condition for odd and even length list 
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        // now slow points to one node before mid
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

// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/submissions/1185522193/

// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/submissions/1185529304/