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
pair<int,ListNode *> lengthOfLinkedList(ListNode *head)
{
    int count = 1;
    if (!head)
        return make_pair(0,head);
    ListNode *curr = head;
    while (curr->next != NULL)
    {
        count++;
        curr = curr->next;
    }
    return make_pair(count,curr);
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        pair<int,ListNode *> val=lengthOfLinkedList(head);
        int len=val.first;
        ListNode *tail=val.second;
        k=k%len;
        if(k==0)
            return head;
        tail->next=head;
        int count=1;
        ListNode * curr=head;
        while(curr->next!=NULL)
        {
            if(count==len-k)
                break;
            curr=curr->next;
            count++;
        }
        head=curr->next;
        curr->next=NULL;
        return head;
        
    }
};
int main()
{

    return 0;
}

// https://leetcode.com/problems/rotate-list/submissions/1187678034/