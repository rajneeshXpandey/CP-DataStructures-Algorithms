class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int dp[n][3]; 
        /**
        states:
        0->bought-state, 1->sold-stateProfit, 2->CoolDown Profit 
        
        transitions:
        bought from Cooldown state
        sold from bought state
        cooldown from sold state.
        */
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][2]-prices[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i]);
            dp[i][2] = max(dp[i-1][1],dp[i-1][2]);
        }
        
        return dp[n-1][1];
    }
};
