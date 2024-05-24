#include<bits/stdc++.h> 
using namespace std;

class Node
{
 public: 
    int val;
    Node *next;
    Node(int data)
    {
       val = data;
       next = nullptr;
    }
};  


class Queue
{
public:
    int size = 0;
    Node *front=NULL;
    Node *rear=NULL;
    bool Empty();
    void Enqueue(int value);
    void Dequeue();
    int Peek();
};  
bool Queue ::  Empty()
{
   return front==NULL;
}  
int Queue :: Peek()
{
   if(front==NULL)
    return -1;

    return front->val;
}   
void Queue :: Enqueue(int value)
{
    Node *ptr=new Node(value);
   if(rear==NULL) // first element insertion
   {
    rear=ptr;
    front=ptr;
   }
   else
   {
    rear->next=ptr;
    rear=ptr;
   }
   size++;
}      
void Queue :: Dequeue() 
{
    if(front==NULL) // underflow
        return;
    Node *ptr=front;
    if(front==rear) // last element deletion
    {
        front=NULL;
        rear=NULL;
    }
    else
    {
        front=front->next;
    }
    delete ptr;
    size--;
}   
int main()

{
    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Dequeue();
    cout<<"The size of the Queue is "<<Q.size<<endl;
    cout<<"The Peek element of the Queue is "<<Q.Peek()<<endl;
    return 0;
}   

// https://www.codingninjas.com/studio/problems/implement-queue-using-linked-list_8161235?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION