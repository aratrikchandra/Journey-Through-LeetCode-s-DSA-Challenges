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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *slow=head,*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL) // generic condition for odd and even length list 
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};
int main()
{

    return 0;
}

// https://leetcode.com/problems/middle-of-the-linked-list/