 #define ll long long 
class Solution { 
 int dp[21][10001];
public:  
  int targetsum(vector<int> arr,int s,int n){
    
    if(n==0)
    {
      if (s == 0)
            return 1;
        else
            return 0;
    }

    if(dp[n][s]!=-1)
      return dp[n][s];
    if (arr[n - 1] <= s){
      dp[n][s] = targetsum(arr,s-arr[n-1],n-1)+targetsum(arr,s,n-1);
    return dp[n][s];}
    else
      {dp[n][s] = targetsum(arr,s,n-1);
    return dp[n][s];
    }
  }
int findTargetSumWays(vector<int> &arr, int S)
{
  
    int N = arr.size();
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }
   if(S > sum)
      return 0;
    if ((S + sum) % 2 != 0)
        return 0;  
    int s = (S + sum) / 2;
    memset(dp,-1,sizeof(dp));
   return targetsum(arr,s,N);
}
};
