#include <bits/stdc++.h>
using namespace std;

// better:using two hashmap(variant of bucket sort)
string frequencySort1(string s) {
         unordered_map<char,int> umap;
    for(int i=0;i<s.length();i++) // freq count of each character
        umap[s[i]]++;
    map<int,vector<char>> mp;   // freq-> character list mapping
    for(auto it:umap){
        mp[it.second].push_back(it.first);
    }
    string ans="";
    for(auto it=mp.rbegin();it!=mp.rend();it++){
        int count=it->first;
        vector<char> arr=it->second;
        for(int i=0;i<arr.size();i++){
                ans=ans+string(count,arr[i]);
        }
    }
    return ans;
}
string frequencySort(string s) {
             unordered_map<char,int> umap;
    for(int i=0;i<s.length();i++) // freq count of each character
        umap[s[i]]++;

        priority_queue<pair<int,char>> pq;

        for(auto it:umap){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            int count=pq.top().first;
            char ch=pq.top().second;
            ans=ans+string(count,ch);
            pq.pop();

        }
        return ans;
}
// https://leetcode.com/problems/sort-characters-by-frequency/submissions/1216196286/
int main(){
  
  string s="treepuyggyigggiuuguo";
  cout<<frequencySort(s);
  
return 0;
}