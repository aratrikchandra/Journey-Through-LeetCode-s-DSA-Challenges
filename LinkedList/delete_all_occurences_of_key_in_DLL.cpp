#include <bits/stdc++.h>
using namespace std;
class Node
{ // user defined data structure
public:
    int data;
    Node *prev;
    Node *next;

public:
    Node(int data1, Node *prev1, Node *next1) // constructor 1
    {
        data = data1;
        prev = prev1;
        next = next1;
    }
    Node(int data1) // constructor 2
    {
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};
Node *deleteAllOccurrences(Node *head, int k) {
  // Write your code here
  Node *last = NULL;
  Node *front = NULL;
  Node *curr = head;
  while (curr != NULL) {
    if (curr->data == k) {
      if (curr == head) {
        head=head->next;
      } 
        front = curr->next;
        last = curr->prev;
        if(front!=NULL)
        front->prev = last;
        if(last!=NULL)
        last->next = front;
        Node *temp = curr;
        curr = front;
        free(temp);
    } else
      curr = curr->next;
  }
  return head;
}
int main(){
  
  
  
return 0;
}
// https://www.codingninjas.com/studio/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION