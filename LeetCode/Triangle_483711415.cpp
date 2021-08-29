class Solution {
public:
   int dp[201][201];
    int solve(vector<vector<int>>& arr,int row, int i,int n)
    {
      if(row>=n)
        return 0;
      int sum1=0,sum2=0;
      if(dp[row+1][i]==-1)
        sum1 = arr[row][i]+solve(arr,row+1,i,n);
      else
        sum1 = dp[row+1][i]+arr[row][i];
      if(dp[row+1][i+1]==-1)
        sum2 = arr[row][i+1]+solve(arr,row+1,i+1,n);
      else
        sum2 = dp[row+1][i+1]+arr[row][i+1];
      return dp[row][i] = min(sum1 , sum2);  
    }
    int minimumTotal(vector<vector<int>>& triangle) {
      memset(dp,-1,sizeof(dp));
      int n = triangle.size();
      return solve(triangle,1,0,n)+triangle[0][0];
    }
};
