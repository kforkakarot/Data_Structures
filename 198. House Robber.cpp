/* 1D dp question maximum sum of non adjacent subsequence*/
class Solution {
public:
    
    
    int fun(int index, vector<int>& nums,vector<int>& dp)
    {
        if(index==0)
            return nums[index];
        if(index<0)
            return 0;
        
        if(dp[index]!=-1)
            return dp[index];
        
        int pic=nums[index]+fun(index-2,nums,dp);
        int notpick=fun(index-1,nums,dp);
        return (dp[index]=max(pic,notpick));
        
    }
    int rob(vector<int>& nums) {
        
    vector<int> dp(101,-1);
        //memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return fun(n-1,nums,dp);
        
    }
};
