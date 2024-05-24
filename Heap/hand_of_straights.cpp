#include <bits/stdc++.h>
using namespace std;
bool isNStraightHand(vector<int>& hand, int k) {
        int n=hand.size();
        // edge case
        if(n%k!=0)
        return false;
        unordered_map<int,int> mp;
        for(auto it:hand){  // storing freq count
            mp[it]++;
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it: mp)  // pushing distinct elements into the heap
        pq.push(it.first);
        while(!pq.empty()){
            int start=pq.top(); // first element of a group
            for(int i=start;i<start+k;i++){
                if(mp[i]==0){  // if the element is not present anymore
                    return false;
                }
                else{
                    mp[i]--;
                    if(mp[i]==0){  // if the element is no more present in future
                        if(i!=pq.top()) // if the element is not the min among available elements
                        return false;
                        else{
                            pq.pop();
                        }
                    }
                }
                
            }
        }
        return true;
}
int main(){
  
  
  
return 0;
}