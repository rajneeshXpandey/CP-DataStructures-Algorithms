int dx[] = {0 , 0 , 1, -1 };
int dy[] = {1 , -1 , 0 , 0 };

class Solution {
public:

bool dfs(vector<vector<char>>& board, string word,int &idx,vector
    <vector<bool>>& visi,int x,int y){
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || 
            board[x][y]!=word[idx] || visi[x][y])
            return false;  
        visi[x][y] = 1;
        if((idx==word.size()-1) and board[x][y]==word[idx]) return 
            true;
        idx++;
        for(int i=0;i<4;i++){
            int xx = x+dx[i], yy = y+dy[i]; 
            if(dfs(board,word,idx,visi,xx,yy))
                return true;
        }
        visi[x][y] = 0;
        idx--;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visi(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j])
                {   
                    int idx = 0;
                    if(dfs(board,word,idx,visi,i,j))
                         return true;
                }
            }
        }
        return false;
    }
};
