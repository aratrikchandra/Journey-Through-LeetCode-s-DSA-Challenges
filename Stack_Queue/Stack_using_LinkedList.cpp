#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class Stack  // top behaves as head
{
    
public:
    int size;
    Node *top;
    Stack()  // constructor
    {
        size=0;
        top=NULL;
    }

    int getSize()
    {
       return size;
    }

    bool isEmpty()
    {
        return top==NULL;
    }

    void push(int data)  // insertion happens always at begin
    {
       Node *ptr=new Node(data);
       ptr->next=top;
       top=ptr;
       size++;
    }

    void pop()  // deletion happens always at begin
    {
        if(isEmpty())
        return;

        Node *ptr=top;
        top=top->next;
        ptr->next=NULL;
        delete ptr;
        size--; 
    }

    int getTop()
    {
        if(isEmpty())
        return -1;

        return top->data;
    }
};
int main()
{
    Stack s;
    s.push(10);
    cout << "stack's top element: " << s.getTop() << "\n";
    s.push(20);
    s.push(30);
    s.pop();
    cout << "stack's top element: " << s.getTop() << "\n";
    s.push(10);
    s.push(10);
    s.pop();
    cout << "Stack size: " << s.getSize() << "\n";
    cout << "Stack empty or not? " << s.isEmpty() << "\n";
    cout << "stack's top element: " << s.getTop() << "\n";
    return 0;
}

// https://www.codingninjas.com/studio/problems/implement-stack-with-linked-list_1279905?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION