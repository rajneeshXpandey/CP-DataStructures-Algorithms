int dx[] = {0 ,0 , 1, -1};
int dy[] = {1 ,-1 , 0, 0};
class Solution {
public:
    void dfs(vector<vector<int>>& mat,vector<int>& visi,int x,int n){
       
        visi[x] = 1;
        for(int i=0;i<n;i++){
            if(!visi[i] and mat[x][i]==1)
             dfs(mat,visi,i,n);
        }  
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
                if(visited[i]==0)
                {
                    dfs(isConnected,visited,i,n);
                    ans++;
                }
        }
        return ans;
    }
};
