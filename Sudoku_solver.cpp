/*Strivers solution for sudoku solver using back tracking learnt from striver
leetcode: 37. Sudoku Solver
*/
class Solution {
public:
    
    bool isSafe(vector<vector<char>> boards,int row,int col,char c)
    {
        for(int i=0;i<9;i++)
        {
            if(boards[row][i]==c)
                return false;
            if(boards[i][col]==c)
                return false;
            if(boards[3*(row/3) + i/3][3*(col/3) + i%3]==c)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& boards)
    {
        for(int i=0;i<boards.size();i++)
        {
            for(int j=0;j<boards[0].size();j++)
            {
                if(boards[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(isSafe(boards,i,j,c)==true)
                        {
                            boards[i][j]=c;
                            if(solve(boards)==true)
                                return true;
                            else
                                boards[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool var=solve(board);
            
    }
};
