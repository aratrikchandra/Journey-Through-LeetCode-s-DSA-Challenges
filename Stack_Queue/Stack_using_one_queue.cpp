#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
      q.push(x);
      for(int i=1;i<q.size();i++)
      {
        int val=q.front();
        q.pop();
        q.push(val);
      }  
    }
    
    int pop() {
        if(q.empty()) // underflow
            return -1;
        int val=q.front();
        q.pop();
        return val;
    }
    
    int top() {
        if(q.empty()) // underflow
            return -1;
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

// https://leetcode.com/problems/implement-stack-using-queues/submissions/1191250910/
int main(){
  
  
  
return 0;
}