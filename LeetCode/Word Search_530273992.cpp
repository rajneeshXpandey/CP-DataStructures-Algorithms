int dx[] = {0 , 0 , 1, -1 };
int dy[] = {1 , -1 , 0 , 0 };

class Solution {
public:
 // vector<pair<int,int>> path;
bool dfs(vector<vector<char>>& board, string word,int &idx,int x,int y
    ){
if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y]!
    =word[idx] || board[x][y]=='#')
            return false; 
        char temp = board[x][y];
        
        if((idx==word.size()-1) and board[x][y]==word[idx]) return 
            true;
        idx++;
        board[x][y]='#';
        for(int i=0;i<4;i++){
            int xx = x+dx[i], yy = y+dy[i]; 
            if(dfs(board,word,idx,xx,yy))
                return true;
        }
        board[x][y]=temp;
        idx--;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j])
                {   
                    int idx = 0;
                    if(dfs(board,word,idx,i,j))
                    {
                      // for(auto p : path)
                      //      cout<<p.first<<' '<<p.second<<endl;
                      return true;  
                    }
                         
                }
            }
        }
        return false;
    }
};
