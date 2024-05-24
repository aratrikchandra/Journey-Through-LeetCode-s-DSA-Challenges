#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode(int val1) {
            val = val1;
            next = NULL;
        }
};
//utility function to insert ListNode at the end of the linked list
void insertNode(ListNode* &head,int val) {
    ListNode* newNode = new ListNode(val);
    
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    ListNode* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}


// Better Approach
/*
int lengthOfLinkedList(ListNode *head)
{
    int count = 0;
    if (!head)
        return count;
    ListNode *curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

//utility function to check presence of intersection
ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        if(head1==NULL || head2==NULL)
         return NULL;
        int len1=lengthOfLinkedList(head1);
        int len2=lengthOfLinkedList(head2);
        int diff;
        if(len1<len2){
            diff=len2-len1;
            ListNode *temp=head1;
            head1=head2;
            head2=temp;
        }
        else
        {
           diff=len1-len2;       
        }
        ListNode *ptr1=head1,*ptr2=head2;
        for(int i=0;i<diff;i++)
        {
            ptr1=ptr1->next;
        }
        while(ptr1!=NULL && ptr2!=NULL)
        {
            if(ptr1==ptr2)
                return ptr1;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
         return NULL;
    }
*/

// Optimal Approach
 ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        if(head1==NULL || head2==NULL)
         return NULL;
         ListNode *ptr1=head1,*ptr2=head2;
        while(ptr1!=NULL && ptr2!=NULL)
        {
            if(ptr1==ptr2)
                return ptr1;
            ptr1=ptr1->next;
            if(ptr1==NULL)
                ptr1=head2;
            ptr2=ptr2->next;
            if(ptr2==NULL)
                ptr2=head1;
        }
         return NULL;
}


//utility function to print linked list created
void printList(ListNode* head) {
    while(head->next != NULL) {
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<head->val<<endl;
}
int main() {
    // creation of both lists 
    ListNode* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    ListNode* head1 = head;
    head = head->next->next->next;
    ListNode* headSec = NULL;
    insertNode(headSec,3);
    ListNode* head2 = headSec;
    headSec->next = head;
    //printing of the lists
    cout<<"List1: "; printList(head1);
    cout<<"List2: "; printList(head2);
    //checking if intersection is present
    ListNode* answerNode = getIntersectionNode(head1,head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->val<<endl;
    return 0;
}

// https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/1187819730/

// https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/1187851365/