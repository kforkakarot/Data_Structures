/*The most optimizes solution with TC:O(N), SC:O(1)
1D dp solution similar to House Robber 1
*/
class Solution {
public:
    int fun(vector<int> &a)
    {   int n=a.size();
        int prev= a[0];
       int prev2= 0;
        
        for(int i=1;i<n;i++)
        {
        int take=a[i]+ ((i>1)?prev2:0);
        int notake= prev;
        int curi=max(take,notake);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int n=nums.size();
        vector<int> temp1(n-1),temp2(n-1);
        
        for(int i=0;i<n;i++)
        {
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
           
        }
        
        
        return max(fun(temp1),fun(temp2));
    }
};
