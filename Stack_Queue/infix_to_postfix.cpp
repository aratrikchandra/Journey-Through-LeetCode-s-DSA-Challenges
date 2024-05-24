#include <bits/stdc++.h>
using namespace std;

int priority(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;

    return 0; // in case not above
}
string infixToPostfix(string s)
{
    int n = s.size();
    stack<char> st;
    string result = "";
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (isalpha(c) || isdigit(c)) // if c is any variable or digit basically an operand
            result += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {                                                            // operator found
            while (!st.empty() && priority(st.top()) >= priority(c)) // assumin all are left-associative
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}
int main()
{
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " << exp << endl;
    cout << infixToPostfix(exp);
    return 0;
}

// https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1