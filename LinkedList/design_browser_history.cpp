#include <bits/stdc++.h>
using namespace std;
// we should think of doubly linked list as a potential data structure as here the size is dynamic
// and we have to move back and front with k steps(no single linked list won't work)
class Node
{ // user defined data structure
public:
    string data;
    Node *left;
    Node *right;

public:
    Node(string data1, Node *left1, Node *right1) // constructor 1
    {
        data = data1;
        left = left1;
        right = right1;
    }
    Node(string data1) // constructor 2
    {
        data = data1;
        left = nullptr;
        right = nullptr;
    }
};
class BrowserHistory {
    private:
    Node *head;
public:
    Node *last;
    BrowserHistory(string homepage) {
        head=new Node(homepage);
        last=head; // last denotes the current page we are in
    }
    
    void visit(string url) {
        Node *temp=new Node(url);
        last->right=temp;
        temp->left=last;
        last=temp;
    }
    
    string back(int steps) {
        while(last->left!=NULL)
        {
            if(steps==0)
                break;
            last=last->left;
            steps--;
        }
        return last->data;
    }
    
    string forward(int steps) {
        while(last->right!=NULL)
        {
            if(steps==0)
                break;
            last=last->right;
            steps--;
        }
        return last->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
int main(){
  
  
  
return 0;
}