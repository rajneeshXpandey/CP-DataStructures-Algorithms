class Solution {
public:
    int maxProfit(vector<int>& prices) {
             int prof1 = 0;
             int prof2 = 0;
        

        int n = prices.size();
        
        int dp[n][2];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n-1;i++)
        {
            if(i>0) dp[i][0] = max(dp[i-1][0],prof1);
            if(prices[i]<prices[i+1])
            {
                int buy = prices[i];
                while(i<n-1 and buy<prices[i+1])
               {     i++;
                 prof1 = max(prof1 ,prices[i]-buy);
                 dp[i][0] = max(dp[i-1][0],prof1);
               }
            
            }
        }
        for(int i=n-1;i>0;i--)
        {
            if(i<n-1) dp[i][1] = max(dp[i+1][1],prof2);
            if(prices[i]>prices[i-1])
            {
                int buy = prices[i];
             while(i>0 and buy>prices[i-1])
               {      i--;
                    prof2 = max(prof2,buy-prices[i]);
                    dp[i][1] = max(dp[i+1][1],prof2);
               }
                
            }
           
        }
       int ans = INT_MIN; 
       for(int i=0;i<n;i++)
          { 
           // cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
           ans = max(ans,dp[i][0]+dp[i][1]);
          }
       // cout<<"------"<<endl; 
    return ans;
    }
};
