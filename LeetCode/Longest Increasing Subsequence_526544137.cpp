class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // O(N^2) : using Dynamic Programming      
        //     dp[i] --> give the lis ending at i
        //         now we can just have to find max of all dp[i]
        
        int n = nums.size();
        int dp[n];
        for(int i=0;i<n;i++)
           dp[i] = 1;
        int maxx = 1;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]>nums[j])
                   {
                    dp[i] = max(dp[i],dp[j]+1);
                    }
                
            }
            maxx = max(maxx,dp[i]);
        }
        return maxx;
    }
};
