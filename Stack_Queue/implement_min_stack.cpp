#include <bits/stdc++.h>
using namespace std;

// better approach
class MinStack
{
    stack<pair<int,int>> st; // {val,mini}
public:
    MinStack()
    {
    }

    void push(int val)
    {
        if(st.empty())
        {
            st.push({val,val});
            return;
        }
        int mini=st.top().second;
        if(val<mini){
            mini=val;
        }
        st.push({val,mini});
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
       return st.top().first; 
    }

    int getMin()
    {
        return st.top().second;
    }
};
// https://leetcode.com/problems/min-stack/submissions/1283122777/


// optimal approach
class MinStack
{
private:
    stack<long long> st;
    long long mini;

public:
    MinStack()
    {
        mini = INT_MAX;
    }

    void push(int val)
    {

        if (st.empty())
        {
            st.push(val);
            mini = val;
            return;
        }

        if (val < mini)
        {
            st.push(2 * (long long)val - mini); // modified value
            mini = val;
        }
        else
            st.push(val);
    }

    void pop()
    {
        if(st.empty()) return;
        long long t=st.top();
        if (t < mini) // modified value
        {
            mini = 2 * mini - t;
        }
        st.pop();
    }

    int top()
    {
        if (st.empty()) return -1;
        if(st.top()<mini) // modified value
        return mini;
        else
        return st.top();
    }

    int getMin()
    {
        return mini;
    }
};
// https://leetcode.com/problems/min-stack/submissions/1283118921/


int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << "getMin: " << obj->getMin() << endl;  // Should print -3
    obj->pop();
    cout << "top: " << obj->top() << endl;        // Should print 0
    cout << "getMin: " << obj->getMin() << endl;  // Should print -2
    return 0;
}
