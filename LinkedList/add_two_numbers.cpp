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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        ListNode *ptr1 = l1, *ptr2 = l2;
        int carry = 0;
        while (ptr1 != NULL || ptr2 != NULL)
        {
            int val1 = ptr1 == NULL ? 0 : ptr1->val;
            int val2 = ptr2 == NULL ? 0 : ptr2->val;
            int sum = val1 + val2 + carry;
            ListNode *temp = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = temp;
            curr = temp;
            if (ptr1 != NULL)
                ptr1 = ptr1->next;
            if (ptr2 != NULL)
                ptr2 = ptr2->next;
        }
        if (carry > 0)
        {
            ListNode *temp = new ListNode(carry);
            curr->next = temp;
        }
        return dummy->next;
    }
};
int main()
{

    return 0;
}
// https://leetcode.com/problems/add-two-numbers/