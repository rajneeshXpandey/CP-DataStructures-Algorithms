int dx[] = {0 ,0 , 1, -1};
int dy[] = {1 ,-1 , 0, 0};
class Solution {
public: 
void dfs(vector<vector<char>>& mat,vector<vector<int>>& visi,int x,int 
    y,int n,int m){
       if(x<0 || y<0 || x>=n || y>=m || mat[x][y]=='0' || visi[x][y])
            return;
        visi[x][y] = 1;
        for(int i=0;i<4;i++){
            dfs(mat,visi,x+dx[i],y+dy[i],n,m);
        }  
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> visi(n,vector<int>(m,0));
        int count = 0;
        
        for(int i=0;i<n;i++)
          for(int j=0;j<m;j++)
               if(!visi[i][j] and grid[i][j]=='1')
               {
                   dfs(grid,visi,i,j,n,m);
                   count++;
               }
        
        return count;
            
    }
};
