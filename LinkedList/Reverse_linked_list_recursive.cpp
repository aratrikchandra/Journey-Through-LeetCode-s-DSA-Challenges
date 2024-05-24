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
    ListNode* reverseList(ListNode* head) {
        // base case
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *front=head->next;
        ListNode *newHead=reverseList(head->next);
        front->next=head;
        head->next=NULL;
        return newHead;
    }
};
int main()
{

    return 0;
}
// https://leetcode.com/problems/reverse-linked-list/submissions/1184217792/