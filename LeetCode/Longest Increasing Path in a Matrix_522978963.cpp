class Solution {
public:
   const int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    
int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i
    ,int j,int n,int m){
        if(dp[i][j]!=0) return dp[i][j];
    
        int maxx = 1;
            
        for(auto d: dir){
            int x = i+d[0], y = j+d[1];
            if(x<0 || y<0 || x>=n || y>=m || matrix[i][j]
                >=matrix[x][y])
                 continue;
            maxx = max(1+dfs(matrix,dp,x,y,n,m),maxx);
         }
       return dp[i][j] = maxx;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
        
    int ans = 1;
        
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){ 
            ans = max(ans,dfs(matrix,dp,i,j,n,m));
        }
    }
    return ans;
        
    }
};
