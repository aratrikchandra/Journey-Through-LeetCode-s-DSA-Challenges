#include <bits/stdc++.h>
using namespace std;

class CircularQueue{
    public:
    vector<int> arr;
    int front,rear;
    int size;
    CircularQueue(int n){
        arr.resize(n);
        front =-1;
        rear=-1;
        size=n;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int e){
        if((rear+1)%size==front) // overflow
            return false;
        if(rear==-1) // first element insertion
        {
            front=0;
            rear=0;
        }
        else{
            rear=(rear+1)%size;
        }
        arr[rear]=e;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front==-1) // underflow
            return -1;
        int val=arr[front];
        if(front==rear) //last element deletion
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%size;
        }
        return val;
    }
};
int main(){
  
  
  
return 0;
}

// https://www.codingninjas.com/studio/problems/circular-queue_1170058?leftPanelTabValue=SUBMISSION