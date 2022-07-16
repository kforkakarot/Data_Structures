/*leetcode 51 N-queens it can be optimized by using hashsets for lower-diagonal and upper-diagonal and  same-row
you can find the optimized solution in previous file*/
class Solution {
public:
    
    bool issafe(int row,int col,vector<string> board,int n)
    {
        for(int i=0;i<col;i++)
            if(board[row][col]=='Q')
                return false;
        
        int r=row;
        int c=col;
        
        while(r>=0 && c>=0)
        {
            if(board[r][c]=='Q')
                return false;
            r--;
            c--;
        }
        c=col;
        r=row;
        while(r<n && col>=0)
        {
            if(board[r][c]=='Q')
                return false;
            r++;
            c--;
        }
        return true;
    }
    void solve(vector<vector<string>>& ans,vector<string>& board,int col,int n)
    {
        if(col==n-1)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(issafe(row,col,board,n)){
                board[row][col]='Q';
                solve(ans,board,col+1,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        
        solve(ans,board,n,0);
        return ans;
        
    }
};
