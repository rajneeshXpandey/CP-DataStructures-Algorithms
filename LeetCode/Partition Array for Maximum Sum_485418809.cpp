class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
      int n = arr.size();
      int dp[n+1];
      memset(dp,0,sizeof(dp));

      for(int i=1;i<=n;i++)
      {
        int mx = 0;
        int curMax = 0;
        for(int j=1;j<=k and (i-j)>=0;j++)
         { 
          curMax = max(curMax, arr[i - j]);
          mx = max(mx, dp[i-j]+curMax*j);
         }
        dp[i] = mx;
      }
      return dp[n];
    }
  
};
