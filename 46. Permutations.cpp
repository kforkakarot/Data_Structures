/* recursive permutation of array*/

class Solution {
public:
    
    void permute(vector<int> nums,int i,vector<vector<int>> &dp)
    {
        if(i==nums.size())
        {
            dp.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            permute(nums,i+1,dp);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n =nums.size();
        
        vector<vector<int>> dp;
        
        permute(nums,0,dp);
        return dp;
        
        
    }
};
