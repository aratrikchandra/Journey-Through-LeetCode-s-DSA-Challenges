#include <bits/stdc++.h>
using namespace std;
class Queue {

	int front, rear;
	vector<int> arr;

public:
	Queue()
	{
		front = -1;
		rear = -1;
		arr.resize(100001);
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{
		if(rear==arr.size()-1) // overflow
            return;
        if(rear==-1) // first element insertion
        {
            front=0;
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=e;
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
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
            front++;
        }
        return val;
	}
};

int main(){
  
  
  
return 0;
} 
// https://www.codingninjas.com/studio/problems/implement-queue-using-arrays_8390825?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION