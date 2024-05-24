#include<bits/stdc++.h>
using namespace std;

class Solution {
    // bi-partite graphs are 2 colorable
private: 
   bool bfs(int start,vector<int> adj[],vector<int> &color)
   {
     color[start]=0;
     queue<int> q;
    q.push(start);

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        for(auto it: adj[node])
        {
            if(color[it]==-1)  // not visited
            {
                color[it]=!color[node];
                q.push(it);
            }
            else if(color[it]==color[node]) // visited and color matches with adjacent node
                return false;
        }
    }
    return true;
   }
public:
	bool isBipartite(int V, vector<int>adj[]){
	  vector<int> color(V,-1);
      
      for(int i=0;i<V;i++)
      {
        if(color[i]==-1)
        {
          if(bfs(i,adj,color)==false)
            return false;  
        }
      }
      return true;
	}

};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
	
	// V = 4, E = 4
	vector<int>adj[4];
	
	addEdge(adj, 0, 2);
   	addEdge(adj, 0, 3);
    	addEdge(adj, 2, 3);
    	addEdge(adj, 3, 1);

	Solution obj;
	bool ans = obj.isBipartite(4, adj);    
	if(ans)cout << "1\n";
	else cout << "0\n";  
	
	return 0;
}

// https://www.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph