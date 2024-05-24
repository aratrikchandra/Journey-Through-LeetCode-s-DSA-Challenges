#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
vector<int> topoSort(int V, vector<int> adj[])
	{
		vector<int> indegree(V,0);
        vector<int> ans;
        for(int i=0;i<V;i++) // calculating indeg array
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;

        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)  // pushing all nodes with indeg zero in stack
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adj[node])
            {
                indegree[it]--;  // decreasing indeg of adjacent nodes by one
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }

        }
        return ans;
	}
public:
	string findOrder(string dict[], int N, int K) {
		vector<int> adj[K]; // adj list
        for(int i=0;i<N-1;i++)
        {
            string s1=dict[i];
            string s2=dict[i+1];

            int len=min(s1.length(),s2.length());

            for(int j=0;j<len;j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        vector<int> res=topoSort(K,adj);

        string ans="";
        for(auto it:res)
        {
            ans+=char(it+'a');
        }
        return ans;
	}
};

int main() {

	int N = 5, K = 4;
	string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
	Solution obj;
	string ans = obj.findOrder(dict, N, K);

	for (auto ch : ans)
		cout << ch << ' ';
	cout << endl;

	return 0;
}

// https://www.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary