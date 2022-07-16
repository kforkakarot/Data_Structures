/*leetcode 51 N-Queens  optimized solution using hash sets , learned from strivers solution on youtube*/

class Solution {
public:
    
    void solve( vector<vector<string>>& ans, vector<string>& board,int n, int col,vector<int>& upperdiagonal,vector<int>& samerow,vector<int>& lowerdiagonal)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(upperdiagonal[n-1+col-row]==0 && lowerdiagonal[col +row]==0 && samerow[row]==0)
            {
                board[row][col]='Q';
                upperdiagonal[n-1 + col - row]=1;
                lowerdiagonal[row+col]=1;
                samerow[row]=1;
                solve(ans,board,n,col+1,upperdiagonal,samerow,lowerdiagonal);                
                upperdiagonal[n-1+ col-row]=0;
                lowerdiagonal[row+col]=0;
                samerow[row]=0;
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        
        vector<int> upperdiagonal(2*n-1,0), samerow(n,0), lowerdiagonal(2*n-1,0);
        solve(ans,board,n,0,upperdiagonal,samerow,lowerdiagonal);
        return ans;
        
    }
};
