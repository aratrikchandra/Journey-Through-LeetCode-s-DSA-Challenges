#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q1,q2;  // we are using two in-built queues
    MyStack() {
        
    }
    
    void push(int x) {
        if(!q1.empty())
        q1.push(x);
    else
        q2.push(x);

    }
    
    int pop() {
        int val;
       if(q1.empty())
       {
            if(q2.empty())
            {
                return -1;  // underflow
            }else{
                while(q2.size()>1)
                {
                    val=q2.front();
                    q1.push(val);
                    q2.pop();
                }
                val=q2.front();
                q2.pop();
                return val;
            }
       } 
       else{
        while(q1.size()>1)
                {
                    val=q1.front();
                    q2.push(val);
                    q1.pop();
                }
                val=q1.front();
                q1.pop();
                return val;
       }
    }
    
    int top() {
        if(!q1.empty())
            return q1.back();  // element at rear pointer
        else if(!q2.empty())
            return q2.back();  // element at rear pointer
        else return -1;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

// https://leetcode.com/problems/implement-stack-using-queues/submissions/1191242881/
int main()
{
 MyStack* obj = new MyStack();
  obj->push(1);
  obj->push(2);
  int param_2 = obj->pop();
  int param_3 = obj->top();
  bool param_4 = obj->empty();
    return 0;
}
