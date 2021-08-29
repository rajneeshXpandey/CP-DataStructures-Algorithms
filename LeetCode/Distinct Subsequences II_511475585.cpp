class Solution {
public:
    int distinctSubseqII(string s) {
        
        const int mod = 1e9+7;
        
        long long dp[s.size()+1];
        
        unordered_map<char,int> last_occ;
        
        dp[0] = 1;
        
        for(int i=1;i<=s.size();i++)
        {
            dp[i] = (2*dp[i-1])%mod;
            
            if(last_occ.find(s[i-1])!=last_occ.end())
            {
                int j = last_occ.find(s[i-1])->second;
                dp[i] = (dp[i] - dp[j-1] + mod)%mod;
            }
            
            last_occ[s[i-1]] = i;
        }
        
        // for(auto d : dp)
        //      cout<<d<<" ";
        // cout<<endl;
        return (dp[s.size()]-1)%mod;
        
    }
};
