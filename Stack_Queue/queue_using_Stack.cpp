#include <bits/stdc++.h>
using namespace std;
// approach 1 (push O(n), remaining O(1))
class MyQueue
{
public:
    stack<int> s1, s2;
    MyQueue()
    {
    }

    void push(int x)
    {
        // transferring all elements from s1 to s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        // transferring all elements from s2 to s1 again
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        // check underflow
        if (empty())
            return -1;

        int val = s1.top();
        s1.pop();
        return val;
    }

    int peek()
    {
        // check underflow
        if (empty())
            return -1;
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};
// https://leetcode.com/problems/implement-queue-using-stacks/submissions/1289247922/

// approach 2 (push O(1) and remaining amortized O(1))
class MyQueue
{
public:
    stack<int> input, output;
    MyQueue()
    {
    }

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        // check underflow
        if (empty())
            return -1;

        if (!output.empty())
        {
            int val = output.top();
            output.pop();
            return val;
        }
        else
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            int val = output.top();
            output.pop();
            return val;
        }
    }

    int peek()
    {
        // check underflow
        if (empty())
            return -1;

        if (!output.empty())
        {
            int val = output.top();
            return val;
        }
        else
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            int val = output.top();
            return val;
        }
    }

    bool empty()
    {
        return input.empty() && output.empty();
    }
};


// https://leetcode.com/problems/implement-queue-using-stacks/submissions/1289253960/