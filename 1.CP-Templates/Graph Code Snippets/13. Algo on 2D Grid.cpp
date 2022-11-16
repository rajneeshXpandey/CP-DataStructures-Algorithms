int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(vector<vector<int>> &grid,vector<vector<bool>> &visited,int x,int y){
    // add extra check according to coditions in problem
    if (x>=0 and x<grid.size() and y>=0 and y<grid[0].size() and !visited[x][y] and grid[x][y])
        return 1; 
    return 0;
}
********************************************************************************************
// DFS on 2D Grid
void dfsOnGrid(vector<vector<int>> &grid,vector<vector<bool>> &visited,int x,int y){
    visited[x][y] = 1;
    cout<<x<<" "<<y<<endl;
    for(int i=0;i<4;i++){
        if(isValid(grid,visited,x+dx[i], y+dy[i]))
            dfs(grid,visited,x+dx[i], y+dy[i]);
    } 
}

// Function calling
int connected_component=0;
for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
        if(!visited[i][j] and grid[i][j]){
            connected_component++;
            dfsOnGrid(grid,visited,i,j);
        }
    }
}
*********************************************************************************
// BFS on 2D Grid

void bfsOnGrid(vector<vector<int>> &grid,vector<vector<bool>> &visited,vector<vector<int>> &distance,int srcX, int srcY){

    pair<int,int> queue;
    q.push({srcX, srcY});
    distance[srcX][srcY] = 0;
    visited[srcX][srcY] = 1;

    while (!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            if (isValid(grid, visited, x+dx[i], y+dy[i])){
                dist[x+dx[i]][y+dy[i]] = dist[x][y]+1;
                vis[x+dx[i]][y+dy[i]] = 1;
                q.push({x+dx[i], y+dy[i]});
            }
        }    
    }
}    
