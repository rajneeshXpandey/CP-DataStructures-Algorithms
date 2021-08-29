class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int dp[n][2];
        memset(dp,0,sizeof(dp));
        dp[0][0] = INT_MAX;
         if(seats[0])
             dp[0][0] = 0;
        for(int i=1;i<n;i++){
            if(seats[i])
                dp[i][0] = 0;
            else 
                dp[i][0] = (dp[i-1][0]==INT_MAX)?INT_MAX:dp[i-1][0]+1;
        }
        dp[n-1][1] = INT_MAX;
        if(seats[n-1])
         dp[n-1][1] = 0;
        for(int i=n-2;i>=0;i--){
            if(seats[i])
                dp[i][1] = 0;
            else 
                dp[i][1] = (dp[i+1][1]==INT_MAX)?INT_MAX:dp[i+1][1]+1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
        // cout<<dp[i][0] << " "<<dp[i][1]<<endl;
           ans = max({ans,min(dp[i][0],dp[i][1])});
        }
        
        return ans;
        
    }
};
