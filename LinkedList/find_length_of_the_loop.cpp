#include <bits/stdc++.h>
using namespace std;
class Node
{ // user defined data structure
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1) // constructor 1
    {
        data = data1;
        next = next1;
    }
    Node(int data1) // constructor 2
    {
        data = data1;
        next = nullptr;
    }
};
int findLength(Node *slow, Node *fast)
{
    int count = 1;
    slow = slow->next;
    while (slow != fast)
    {
        slow = slow->next;
        count++;
    }
    return count;
}
int lengthOfLoop(Node *head)
{
    // Write your code here
    int count = 0;
    if (head == NULL || head->next == NULL)
        return count;
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL && fast->next->next !=NULL) // generic condition for odd and even length list
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            count = findLength(slow, fast);
            break;
        }
    }
    return count;
}

int main()
{

    return 0;
}
// https://www.geeksforgeeks.org/problems/find-length-of-loop/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-length-of-loop