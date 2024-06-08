#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    // member variable
    Node *links[2];

    // member functions
    bool containsKey(int bit)
    {
        return links[bit] != NULL;
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
    Node *get(int bit)
    {
        return links[bit];
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(long long val)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (val >> i) & 1; // retrieving i-th bit of val
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int findMax(long long val)
    {
        Node *node = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (val >> i) & 1; // retrieving i-th bit of val
                                      // Here, when i becomes 31, it tries to shift val (which is a 32-bit integer) by 31 places, which is undefined behavior in C++.
            // To fix this, you can change the type of val from int to long long which is a 64-bit integer. This will allow you to shift up to 63 places without encountering undefined behavior.
            if (node->containsKey(1 - bit))
            {
                maxXOR = maxXOR | (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxXOR;
    }
};
class Solution
{
public:
        vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
            int n=arr.size();
            vector<int> ans(queries.size(),0);
            // sorting input array
            sort(arr.begin(),arr.end());

            vector<pair<int,pair<int,int>>> offlineQuery;
            int ind=0;
            for(auto &it: queries){
                offlineQuery.push_back({it[1],{it[0],ind++}});
            }
            sort(offlineQuery.begin(),offlineQuery.end());

            Trie trie;
            int ind=0;
            for(auto &it: offlineQuery){
                int mi=it.first;
                int xi=it.second.first;
                int Qindex=it.second.second;

                while (ind<n)
                {
                    if(arr[ind]<=mi){
                        trie.insert(arr[ind]);
                        ind++;
                    }
                    else{
                        break;
                    }
                }
                if(ind==0) // all the elements are greater than mi
               ans[Qindex]=-1;
               else 
                ans[Qindex]=trie.findMax(xi);
            }

            return ans;
    }
};
// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/submissions/1281556057/
int main(){
  
  
  
return 0;
}