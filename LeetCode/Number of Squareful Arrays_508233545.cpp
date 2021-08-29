#define ll long long
class Solution {
public:
    int dp[1<<12][12];
    bool sq(int a,int b)
    {
        ll sum = sqrt(a+b);
        long double sum1 = sqrt(a+b);
        if(sum==sum1)
            return 1;
        return 0;
    }
    int dfs(int node,int mask,vector<int> adj[],int n)
    {
       if(__builtin_popcount(mask)==n)
           return 1;
      // no need to add case of node == n-1  
        if(dp[mask][node]!=-1)
            return dp[mask][node];
        int count = 0;
        for(auto nb : adj[node])
        {
            if(mask & (1<<nb))
                 continue;
            count += dfs(nb,mask|(1<<nb),adj,n);
        }
        return dp[mask][node] = count;
  }
    
    int numSquarefulPerms(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
             for(int j=i+1;j<n;j++)
             {
                 if(sq(nums[i],nums[j]))
                 {
                     adj[i].push_back(j);
                     adj[j].push_back(i);
                 }
             }
        
        // count all the paths from i to N
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            memset(dp,-1,sizeof(dp));
            ans += dfs(i,(1<<i),adj,n);
        }
        
        // remove ans for repeated value  i.e. divide by (k!) k = 
            number of occurance.
            
        for (int i = 0; i < n; i++) {
            int k = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    k++;
                }
            }
            ans /= k;
        }
        
    return ans;

        
    }
};
