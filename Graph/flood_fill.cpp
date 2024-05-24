#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int row,int col,vector<vector<int>> image,vector<vector<int>> &img,int newColor,int delRow[],int delCol[],int iniColor)
    {
        // mark visited
        img[row][col]=newColor;
        int n=img.size();
        int m=img[0].size();
        for(int i=0;i<4;i++)
        {
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];

            // checking for validity
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m)
            {
                if(image[nRow][nCol]==iniColor && img[nRow][nCol]!=newColor)  // important
                {
                    dfs(nRow,nCol,image,img,newColor,delRow,delCol,iniColor);
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image,int sr, int sc, int newColor)
    {
        int n=image.size();
        int m=image[0].size();

        int iniColor=image[sr][sc];

        vector<vector<int>> copy_img = image;
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,1,0,-1};
        dfs(sr,sc,image, copy_img,newColor,delRow,delCol,iniColor);

        return copy_img;
    }
    
};

int main()
{

    vector<vector<int>> image{
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    // sr = 1, sc = 1, newColor = 2
    Solution obj;
    vector<vector<int>> ans = obj.floodFill(image, 1, 1, 2);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }

    return 0;
}

// https://leetcode.com/problems/flood-fill/submissions/