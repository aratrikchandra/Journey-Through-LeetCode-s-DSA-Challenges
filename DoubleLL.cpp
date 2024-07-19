#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node *left;
    Node *right;

    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
Node *createLinkedList(vector<int> &arr){
    int n=arr.size();
    Node *head=NULL;
    if(n==0){
        return head;
    }
    head=new Node(arr[0]);
    Node *tail=head;
    for(int i=1;i<n;i++){
        Node *temp=new Node(arr[i]);
        tail->right=temp;
        temp->left=tail;
        tail=temp;
    }
    return head;
}
void printLinkedList(Node *head){
    Node *ptr=head;
    while(ptr){
        cout<<ptr->val<<" ";
        ptr=ptr->right;
    }
    cout<<endl;
}
int lengthOfLinkedList(Node *head){
    Node *ptr=head;
    int count=0;
    while(ptr){
        count++;
        ptr=ptr->right;
    }
    return count;
}
bool search(Node *head, int target){
    Node *ptr=head;
    while(ptr){
        if(ptr->val==target)
        return true;

        ptr=ptr->right;
    }
    return false;
}
Node *deleteAtBegin(Node *head){
    if(head==NULL)
    return NULL;
    Node *ptr=head;
    head=head->right;
    delete ptr;
    return head;
}
Node *deleteAtEnd(Node *head){
    if(head==NULL)
    return NULL;

    Node *ptr=head;
    while(ptr->right){
        ptr=ptr->right;
    }
    ptr->left->right=NULL;
    delete ptr;
    return head;
}
Node *deleteAtPosition(Node *head, int k){
    int n=lengthOfLinkedList(head);
    if(k==1)
    return deleteAtBegin(head);
    if(k==n)
    return deleteAtEnd(head);
    int count=0;
    Node *ptr=head;
    while(ptr){
        count++;
        if(count==k){
            ptr->left->right=ptr->right;
            ptr->right->left=ptr->left;
            delete ptr;
            break;
        }
        ptr=ptr->right;
    }
    return head;
}
// https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-node-in-doubly-linked-list

Node *insertAfterBegin(Node *head, int item){
    Node *temp=new Node(item);
    temp->right=head->right;
    if(head->right)
    head->right->left=temp;
    
    head->right=temp;
    temp->left=head;

    return head;
}
Node* insertAfterEnd(Node* head, int item) {
    Node* temp = new Node(item);
    Node* ptr = head;

    // Traverse to the last node
    while (ptr->right != nullptr) {
        ptr = ptr->right;
    }

    // Insert the new node at the end
    ptr->right = temp;
    temp->left = ptr;

    return head;
}
Node *insertAfterPosition(Node *head, int item, int k){
    int n=lengthOfLinkedList(head);
    if(k==0)
    return insertAfterBegin(head,item);
    if(k==n-1)
    return insertAfterEnd(head,item);

    Node *temp=new Node(item);
    Node *ptr=head;
    int count=-1;
    while(ptr){
        count++;
        if(count==k){
            temp->right=ptr->right;
            ptr->right->left=temp;
            ptr->right=temp;
            temp->left=ptr;
            break;
        }
        ptr=ptr->right;
    }
    return head;
}
// https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1?page=1&category=doubly-linked-list&sortBy=submissions
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 10, 121, 12, 56, 23};
    vector<int> arr2={1};
    Node *head = createLinkedList(arr);
    printLinkedList(head);
    // printReverseLinkedList(head);
    // cout << "Length of the Linked List: " << lengthOfLinkedList(head) << endl;
    // bool flag=search(head,23);
    // if(flag==true)
    // cout<<"Element is present";
    // else
    // cout<<"Element not present";
    // cout<<endl;
    // head=deleteAtBegin(head);
    // printLinkedList(head);
    // head = deleteAtEnd(head);
    // printLinkedList(head);
    // head = deleteAtPosition(head,4);
    // printLinkedList(head);
    // Node *ptr=head->right->right->right->right;
    // deleteByNode(ptr);
    // printLinkedList(head);

    // head = insertAfterBegin(head, 54);
    // printLinkedList(head);
    // head = insertAfterEnd(head, 5);
    // printLinkedList(head);
    // head=insertAfterPosition(head,455,7);
    // printLinkedList(head);
    // Node *ptr=head->right->right->right->right;
    // insertBeforeNode(ptr,17);
    // printLinkedList(head);
    return 0;
}