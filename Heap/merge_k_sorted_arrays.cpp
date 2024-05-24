#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    int row;
    int col;

    node(int data,int row,int col){
        this->data=data;
        this->row=row;
        this->col=col;
    }
};
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data>b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    vector<int> ans;
    priority_queue<node*,vector<node*>,compare> pq;

    for(int i=0;i<k;i++){
        node *item=new node(arr[i][0],i,0);
        pq.push(item);
    }

    while(!pq.empty()){
        node *temp=pq.top();
        pq.pop();
        ans.push_back(temp->data);
        int row=temp->row;
        int col=temp->col;

        if(col+1<arr[row].size())
        {
            node *ptr=new node(arr[row][col+1],row,col+1);
            pq.push(ptr);
        }
        free(temp);
    }
    return ans;
}
int main(){
  
  vector<vector<int>> arr={{3, 5, 9},{1, 2, 3, 8}};
  int k=2;
  vector<int> ans=mergeKSortedArrays(arr,k);
   for(auto it:ans)
  cout<<it<<" ";
return 0;
}

// https://www.codingninjas.com/studio/problems/merge-k-sorted-arrays_975379?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION