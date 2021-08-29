
int dx[] = {0 , 0 , 1, -1 };
int dy[] = {1 , -1 , 0 , 0 };
class TrieNode {
     public:
        bool isEnd;
        TrieNode *childs[26];
        string word;
            TrieNode(){
                memset(childs, (int)NULL, sizeof(childs));
                isEnd = false;
                word = "";
            }
        /**  containsKey() | get() | put() | setEnd() | isEnd()    */
       // we can ignore it also 
            bool containsKey(char ch){
                return (childs[ch-'a']!=NULL);
              
            }

            TrieNode* get(char ch){
                if(ch-'a'>=0 and ch-'a'<=25)
                 return childs[ch-'a'];
                else return NULL;
            }

            void put(char ch,TrieNode* node){
                childs[ch-'a'] = node;
            }

            void setEnd(){
                isEnd = true;
            }
        
            bool isEnds(){
                return isEnd;
            }

};

// class Trie {
// public:
//     TrieNode *root;
//    /** Initialize your data structure here. */  
//     Trie() {
//         root = new TrieNode();
//     }
//     /** Inserts a word into the trie. */
//     void insert(string word) {
//         TrieNode* node  = root;
//         for(auto ch : word)
//         {
//             if(!node->containsKey(ch))
//                  node->put(ch,new TrieNode());
//             node = node->get(ch);
//         }
//         node->setEnd();
//     }
// };

class Solution {
public:
  
       
   /** Initialize your data structure here. */  
    TrieNode *root = new TrieNode();
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node  = root;
        for(auto ch : word)
        {
            if(!node->containsKey(ch))
                 node->put(ch,new TrieNode());
            node = node->get(ch);
        }
        node->setEnd();
        node->word = word;
    }
    
set<string> ans;
    
void dfs(vector<vector<char>>& board,TrieNode *root,int x,int y){
    if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || 
        board[x][y]=='#' || !(root->get(board[x][y])))
            return; 
      char temp = board[x][y];
      root = root->get(board[x][y]);     
          if(root->isEnd){ 
              ans.insert(root->word);
          }
       board[x][y]='#'; 
        for(int i=0;i<4;i++){
            int xx = x+dx[i], yy = y+dy[i]; 
            dfs(board,root,xx,yy);
        }
        board[x][y]=temp;   
    }
    void isPresent(vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(root->get(board[i][j]))
                   dfs(board,root,i,j);
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector
        <string>& words) {

       for(auto w : words)    
          insert(w);
       isPresent(board);
       vector<string> st;
    for(auto str : ans)
        st.push_back(str);
        
      return st;  
        
    }
};
