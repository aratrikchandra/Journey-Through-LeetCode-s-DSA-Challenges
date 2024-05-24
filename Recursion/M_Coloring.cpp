#include <bits/stdc++.h>
using namespace std;
bool isValid(int vertex,int col,int color[],bool graph[101][101],int n){
        for(int i=0;i<n;i++){
            if(i!=vertex && graph[vertex][i]==1 && color[i]==col)
            return false;
        }
        return true;
}
bool solve(int vertex,int color[],bool graph[101][101], int m, int n){
    // base case
    if(vertex==n){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(isValid(vertex,i,color,graph,n)){
            color[vertex]=i;
            // recursive call
            if(solve(vertex+1,color,graph,m,n)==true)
            return true;
            color[vertex]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    int color[n]={0};
    return solve(0,color,graph,m,n);
}
int main(){  
  
return 0;
}

// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1