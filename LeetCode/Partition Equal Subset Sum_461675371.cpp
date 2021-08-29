class Solution {
  int dp[201][10001];
public:
    bool canPartition(vector<int>& arr) {
        int N = arr.size();
        int sum = 0;
        // code here
        for(int i=0;i<N;i++)
            sum+=arr[i];
            
        if(sum%2 != 0)
         return 0;
            
        sum = sum/2;   
        
      for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i==0)
                  dp[i][j]=0;
                if(j==0)
                  dp[i][j]=1;
            }
        }
      dp[0][0]=1;
      
       for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=sum;j++)
            {
               if(arr[i-1]<=j) 
                dp[i][j] = (dp[i-1][j-arr[i-1]] or dp[i-1][j]);
               else 
                 dp[i][j] = dp[i-1][j];
            }
        }
      
      return dp[N][sum];
    }
};
