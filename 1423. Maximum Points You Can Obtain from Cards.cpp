/*Google's most asked interview question in first half of 2021*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l=0;
        int n=cardPoints.size();
        int r=n-k;
        int total=0;
        for(int i=r;i<n;i++)
            total+=cardPoints[i];
        int sum=total;
              
        
        while(r<cardPoints.size())
        {
            total+=cardPoints[l]-cardPoints[r];
            sum=max(total,sum);
            l+=1;
            r+=1;
        }
        
        return sum;
    }
};
