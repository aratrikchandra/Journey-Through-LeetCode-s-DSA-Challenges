#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c)
{
    if(!isdigit(c) && !isalpha(c) && !isspace(c))
    return true;
    else
    return false;
}
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
        {   if(isOperator(c)){
            if(c=='^'){                                                       // operator found
            while (!st.empty() && priority(st.top()) >= priority(c)) // here '^' will be left-associative as we are dealing with reverse expression
            {
                result += st.top();
                st.pop();
            }
            }
            else{
              while (!st.empty() && priority(st.top()) > priority(c)) // here '+,-,*,/' will be right-associative as we are dealing with reverse expression
            {
                result += st.top();
                st.pop();
            }  
            }
            st.push(c);
        }
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}
string infixToPrefix(string infix){
    int n=infix.size();

    reverse(infix.begin(),infix.end());
    for(int i=0;i<n;i++)
    {
        if(infix[i]=='(')
        {
            infix[i]=')';
            i++;
        }
        if(infix[i]==')')
        {
            infix[i]='(';
            i++;
        }
    }

    string prefix=infixToPostfix(infix);
    reverse(prefix.begin(),prefix.end());
    return prefix;
}
int main()
{
    string infix = "A + B * C - D / E ^ F * G + H - I * J / K ^ L * M + N - O * P / Q ^ R * S";
    infix.erase(remove(infix.begin(), infix.end(), ' '), infix.end()); 
    cout << "Infix expression: " << infix << endl;
    string actual=infixToPrefix(infix);
    string expected="- + A * B C + - / D * ^ E F G + - H * I / J * ^ K L M + - N * O / P * ^ Q R S";
    expected.erase(remove(expected.begin(), expected.end(), ' '), expected.end()); 
    cout<<"prefix got:"<<actual<<endl;
    if(actual==expected)
    cout<<"passed";
    else
    cout<<"failed";
    return 0;
}