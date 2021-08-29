class Solution {
public:
    int rob(vector<int>& nums) {
         int n = nums.size();
        int dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for(int i=1;i<n-1;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = nums[i]+dp[i-1][0];
        }
        if(n==1) return nums[0];
        int dp2[n][2];
        dp2[1][0] = 0;
        dp2[1][1] = nums[1];
        for(int i=2;i<n;i++){
            dp2[i][0] = max(dp2[i-1][0],dp2[i-1][1]);
            dp2[i][1] = nums[i]+dp2[i-1][0];
        }
        
        int ans = max(max(dp2[n-1][0],dp2[n-1][1]),max(dp[n-2][0],dp[n
            -2][1]));
        
        return ans;
    }
};
