#include <bits/stdc++.h>
using namespace std;
// Stack class.
class Stack {
    
public:
    int topIndex;
    vector<int> arr;
    Stack(int capacity) {
        arr.resize(capacity);
        topIndex = -1;
    }

    void push(int num) {
        // check overflow
        if (isFull())
            return;
        topIndex++;
        arr[topIndex] = num;
    }

    int pop() {
        if (isEmpty())
            return -1;
        int val = arr[topIndex];
        topIndex--;
        return val;
    }
    
    int top() {
        if (isEmpty())
            return -1;
        return arr[topIndex];
    }
    
    bool isEmpty() {
        return topIndex == -1;
    }
    
    bool isFull() {
        return topIndex == arr.size() - 1;
    }
};
// https://www.naukri.com/code360/problems/stack-implementation-using-array_3210209?leftPanelTabValue=SUBMISSION

int main(){
  
  
return 0;
}