/* memoization based solution*/
class Solution {
public:
    
    int f(int i,int j,vector<vector<int>>& a,vector<vector<int>>& dp)
    {
        if(i<0 || j<0)
         return 1000000000;
        
        if(i==0 && j==0)
            return a[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up= a[i][j]+f(i-1,j,a,dp);
        int left=a[i][j]+f(i,j-1,a,dp);
        
        return (dp[i][j]=min(up,left));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return f(m-1,n-1,grid,dp);
        
    }
};
