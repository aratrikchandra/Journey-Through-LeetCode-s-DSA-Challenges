#include <bits/stdc++.h>
using namespace std;
// Stack class.
class Stack {
    
public:
    int topIndex;
    vector<int> arr;
    Stack(int capacity) {
        arr.resize(capacity);
        topIndex=-1;
    }

    void push(int num) {
        if(isFull())
            return;
       topIndex++;
       arr[topIndex]=num;
    }

    int pop() {
        if(isEmpty())
            return -1;
        int val=arr[topIndex];
        topIndex--;
        return val;
    }
    
    int top() {
        if(isEmpty())
            return -1;
        return arr[topIndex];
    }
    
    int isEmpty() {
        return topIndex==-1;
    }
    
    int isFull() {
        return topIndex==arr.size();
    }
    
};

int main(){
  
  
return 0;
}