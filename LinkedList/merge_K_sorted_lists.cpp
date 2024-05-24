#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *merge(ListNode *head1, ListNode *head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    ListNode *dummyNode=new ListNode(-1);
    ListNode *curr=dummyNode;
    ListNode *ptr1=head1;
    ListNode *ptr2=head2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->val<ptr2->val)
        {
            curr->next=ptr1;
            curr=ptr1;
            ptr1=ptr1->next;
        }
        else
        {
            curr->next=ptr2;
            curr=ptr2;
            ptr2=ptr2->next;
        }
    }

    if(ptr1!=NULL)
    {
        curr->next=ptr1;
    }
    else
    {
        curr->next=ptr2;
    }
    return dummyNode->next;
}
// better approach
ListNode* mergeKLists1(vector<ListNode*>& lists) {
     // edge case
        if (lists.empty()) {
            return NULL;
        }
        ListNode *head=lists[0];
        int n=lists.size();
        for(int i=1;i<n;i++)
        {
            head=merge(head,lists[i]);
        }
        return head;
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
     // edge case
        if (lists.empty()) {
            return NULL;
        }
       priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
       int n=lists.size();
        for(int i=0;i<n;i++)
        {
            if(lists[i]!=NULL)
            pq.push(make_pair(lists[i]->val,lists[i]));
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *curr=dummy;
        while(!pq.empty())
        {
            pair<int,ListNode*> it=pq.top();
            pq.pop();
            curr->next=it.second;
            curr=it.second;
            if(it.second->next!=NULL)
            pq.push(make_pair(it.second->next->val,it.second->next));
        }
        return dummy->next;
}

int main(){
  
  
  
return 0;
}
// https://leetcode.com/problems/merge-k-sorted-lists/submissions/1191439945/