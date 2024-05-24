#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val1)
    {
        val = val1;
        next = NULL;
    }
};

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
ListNode *findKthNode(ListNode *head, int k)
{
    if (head == NULL)
        return NULL;
    int count = 1;
    ListNode *ptr = head;
    while (ptr != NULL)
    {
        if (count == k)
            break;
        ptr = ptr->next;
        count++;
    }
    return ptr;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (k == 1 || head == NULL)  // base case
        return head;
    ListNode *temp = head;
    ListNode *nextNode = NULL;
    ListNode *kthNode = findKthNode(temp, k);

    if (kthNode == NULL) {
        return temp;
    }
    nextNode = kthNode->next;
    kthNode->next = NULL;
    ListNode* newHead = reverseList(temp);
    temp->next = reverseKGroup(nextNode, k);
    return newHead;
}

// Function to print the linked list
void printLinkedList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    // Create a linked list with
    // values 5, 4, 3, 7, 9 and 2
    ListNode *head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next = new ListNode(2);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = reverseKGroup(head, 4);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}

// https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/1188683255/