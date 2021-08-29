class Solution {
public:
    int util(int k){
        int n = 30;
        vector<int> dp(n+1,0);
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[k];
    }
    int fib(int n) {
       return util(n);
    }
};
