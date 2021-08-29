class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
          for(int j=0;j<=m;j++){
              if(j==0){
                 dp[i][j] = i; 
              }
              else if(i==0){
                   dp[i][j] = j; 
              }
              else{
                  if(word1[i-1]==word2[j-1])
                      dp[i][j] = dp[i-1][j-1];
                  else{
                      /**
                        Insert a character : i with j-1
                        Delete a character : i-1 with j
                        Replace a character: i-1 with j-1
                      */  
                      dp[i][j] = 1+min(min(dp[i][j-1],dp[i-1][j]),dp[i
                          -1][j-1]);
                  }
              }
          }
        
        
        return dp[n][m];
    }
};
