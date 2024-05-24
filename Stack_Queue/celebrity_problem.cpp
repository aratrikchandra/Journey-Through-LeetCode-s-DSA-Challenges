#include <bits/stdc++.h>
using namespace std;
bool knows(vector<vector<int>> &M,int a,int b)
{
    if(M[a][b]==1)
    return true;
    else 
    return false;
}
int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        st.push(i);
    }

    while(st.size()>1)
    {
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();
        if(knows(M,a,b))  // if a knows b then a can't be a celebrity
        {
            st.push(b);
        }
        else            // if a doesn't know b then b can't be a celebrity
        {
            st.push(a);
        }
    }
    int Celeb=st.top(); // potential celebrity
    bool checkRow=true;
    for(int i=0;i<n;i++)
    {
        if(M[Celeb][i]==1)
        {
            checkRow=false;
            break;
        }
    }
    bool checkCol=true;
    for(int i=0;i<n;i++)
    {
        if(i!=Celeb && M[i][Celeb]==0)
        {
            checkCol=false;
            break;
        }
    }
    if(checkRow && checkCol)
    return Celeb;
    else
    return -1;

}
int main()
{

    vector<vector<int>> M = {{0, 1, 0},
                             {0, 0, 0},
                             {0, 1, 0}};
    int celeb=celebrity(M,3);
    if(celeb==-1)
        cout<<"celebrity not found";
    else
        cout<<"celebrity is: "<<celeb;

    return 0;
}

// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1