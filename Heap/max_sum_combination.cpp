#include <bits/stdc++.h>
using namespace std;
vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        priority_queue<pair<int,pair<int,int>>> pq;
        set<pair<int,int>> st;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        pq.push({a.back()+b.back(),{n-1,n-1}});
        st.insert({n-1,n-1});
        vector<int> ans;
        while(k-- && !pq.empty()){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.first);
            int ind1=it.second.first;
            int ind2=it.second.second;
            if(st.find({ind1,ind2-1})==st.end()){
                if(ind2>0){
                    pq.push({a[ind1]+b[ind2-1],{ind1,ind2-1}});
                    st.insert({ind1,ind2-1});
                }
            }
            if(st.find({ind1-1,ind2})==st.end()){
                if(ind1>0){
                    pq.push({a[ind1-1]+b[ind2],{ind1-1,ind2}});
                    st.insert({ind1-1,ind2});
                }
            }
        }
        return ans;
}
int main(){
int  N = 4;
int K = 5;
vector<int> A = {1, 4, 2, 3};
vector<int> B  = {2, 5, 1, 6};
  vector<int> ans=maxCombinations(N,K,A,B);
    for(auto it:ans)
  cout<<it<<" ";
return 0;
}

// https://www.geeksforgeeks.org/problems/maximum-sum-combination/1