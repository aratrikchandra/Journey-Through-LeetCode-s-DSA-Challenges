#include <bits/stdc++.h>
using namespace std;

// approach1
bool isSafe1(int row,int col,vector<string> &board,int n){
    int r=row;
    int c=col;
    // checking top-left
    while(r>=0 && c>=0){
        if(board[r][c]=='Q')
        return false;
        r--;
        c--;
    }
    r=row;
    c=col;
    // checking bottom-left
    while(r<n && c>=0){
        if(board[r][c]=='Q')
        return false;
        r++;
        c--;
    }
    r=row;
    c=col;
    // checking left
    while(c>=0){
        if(board[r][c]=='Q')
        return false;
        c--;
    }

    return true;
}
// https://leetcode.com/problems/n-queens/submissions/1223761012/

// optimized
bool isSafe(int row,int col,int n,vector<int> &leftRow,vector<int> &upperDiagonal,vector<int> &lowerDiagonal){
    if(leftRow[row]==0 && upperDiagonal[n-1+(col-row)]==0 && lowerDiagonal[row+col]==0)
    return true;
    else
    return false;
}
void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n,vector<int> &leftRow,vector<int> &upperDiagonal,vector<int> &lowerDiagonal){
    // base case
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,n,leftRow,upperDiagonal,lowerDiagonal)){
            // place the queen in board
            board[row][col]='Q';
            // include in hash array
            leftRow[row]=1;
            upperDiagonal[n-1+(col-row)]=1;
            lowerDiagonal[row+col]=1;
            // recursive call for next column
            solve(col+1,board,ans,n,leftRow,upperDiagonal,lowerDiagonal);
            // take out the queen in board
            board[row][col]='.';
            // exclude from hash array
            leftRow[row]=0;
            upperDiagonal[n-1+(col-row)]=0;
            lowerDiagonal[row+col]=0;
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.'); // represents one row at beginning
    for(int i=0;i<n;i++){ // initially board configuration
        board[i]=s;
    }
    vector<int> leftRow(n,0),upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1,0);
    solve(0,board,ans,n,leftRow,upperDiagonal,lowerDiagonal);
    return ans;    
}
// https://leetcode.com/problems/n-queens/submissions/1223806639/
int main(){
    int n = 4; // we are taking 4*4 grid and 4 queens
  vector < vector < string >> ans = solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
return 0;
}