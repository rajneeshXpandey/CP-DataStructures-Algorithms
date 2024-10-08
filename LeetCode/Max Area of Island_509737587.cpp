class Solution {
public:
    int dfs(vector<vector<int>>& visi,vector<vector<int>>& grid,int i
        ,int j,int n,int m)
    {
        if(i<0 or j<0 or i>=n or j>=m or visi[i][j]==1 or grid[i][j]
            ==0)
             return 0;
        
        visi[i][j] = 1;
       return dfs(visi,grid,i-1,j,n,m)+dfs(visi,grid,i+1,j,n,m)+dfs
           (visi,grid,i,j-1,n,m)+dfs(visi,grid,i,j+1,n,m)+1;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int n=grid.size();
         int m=grid[0].size();
        
        vector<vector<int>> visi(n,vector<int>(m,0));
        int area = 0;
        
        for(int i=0;i<n;i++)
          for(int j=0;j<m;j++)
               if(!visi[i][j] and grid[i][j]==1)
               {
                   area = max(area,dfs(visi,grid,i,j,n,m));
               }
        
        return area;
    }
};
