class Solution {
public:
    bool isMatch(string s, string p) {
        
        int n = p.size();
        int m = s.size();
        
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
            {
                if(i==0 and j==0) 
                    dp[i][j] = true;
                else if(i==0)
                    dp[i][j] = false;
                else if(j==0)
                {
                    if(p[i-1]=='*')
                        dp[i][j] = dp[i-2][j];
                    else 
                        dp[i][j] = false;
                }
                else{
                    
                   if(p[i-1]=='*')
                    {
                       /**
                       mississippi
                       mis*is*p*.
                       */
             // mis <=> mis*           
             dp[i][j] = dp[i-2][j];  // mis <=> mis*  --> mis <=> mi
         if(p[i-2]==s[j-1] or p[i-2]=='.') 
            dp[i][j] = dp[i][j] || dp[i][j-1];  // mi/s/ <=> mi/s/s* 
                --> mi <=> mis*
                    }
                    else if(s[j-1]==p[i-1] or p[i-1]=='.')
                         dp[i][j] = dp[i-1][j-1];
                    else if(s[j-1]!=p[i-1])
                        dp[i][j] = false; 
                }
            }
        
        
        return dp[n][m];
    }
};
