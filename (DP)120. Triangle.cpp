/*memoization solution*/

class Solution {
public:
    int f(int i, int j,vector<vector<int>>& a,vector<vector<int>>& dp,int n)
    {
        if(i==n-1)
            return a[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int down= a[i][j]+ f(i+1,j,a,dp,n);
        int diag= a[i][j]+ f(i+1,j+1,a,dp,n);
        return dp[i][j]=min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,triangle,dp,n);
        
    }
};
