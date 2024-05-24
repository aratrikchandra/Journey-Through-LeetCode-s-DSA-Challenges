#include <bits/stdc++.h>
using namespace std;
void solve(int row,int col,vector<vector<int>> &visited,string &path,vector<string> &ans,vector<vector<int>> &m,int n){
    // base case
    if(row==n-1 && col==n-1){
        ans.push_back(path);
    }
    // mark the current cell as visited
    visited[row][col]=1;
    // we have traverse four directions but in lexicographical order (DLRU)
    int dr[]={1,0,0,-1};
    int dc[]={0,-1,1,0};
    string way="DLRU";
    for(int i=0;i<4;i++){
        int newRow=row+dr[i];
        int newCol=col+dc[i];
        // first four are array out of bound check
        if(newRow>=0 && newCol>=0 && newRow<n && newCol<n && m[newRow][newCol]==1 && !visited[newRow][newCol]){
            path=path+way[i];
            // recursive call
            solve(newRow,newCol,visited,path,ans,m,n);
            path.pop_back();
        }
    }
    // mark the current cell as unvisited
    visited[row][col]=0;
}
vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string path="";
        vector<vector<int>> visited(n,vector<int> (n,0));
        // edge case(when starting point is unreachable)
        if(m[0][0]==0)
        return ans;

        solve(0,0,visited,path,ans,m,n);
        return ans;
}
int main(){

return 0;
}

// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1