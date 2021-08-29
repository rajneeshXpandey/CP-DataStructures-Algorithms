
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
           
        int m  = box.size();
        int n = box[0].size();
        
        for(int i=0;i<m;i++)
        {
           vector<int> idx;
           idx.push_back(-1); 
            
           for(int j=0;j<n;j++)
                 if(box[i][j]=='*')
                     idx.push_back(j);
            
          idx.push_back(n); 
            
          for(int st=0;st<idx.size()-1;st++)  
          {
            int stone = 0;
            for(int j=idx[st]+1;j<=idx[st+1]-1;j++)
                 if(box[i][j]=='#')
                     stone++;
              
            int j=idx[st+1]-1;
              
            for(;j>=idx[st]+1;j--)
            {
                if(stone==0)
                    break;
                if(stone>0)
                {
                   box[i][j] = '#';
                   stone--; 
                }
                 
            }
            while(j>=idx[st]+1)
            {
              box[i][j] = '.';
              j--;              
            }
          }
            
        }

        
        vector<vector<char>> ans(n,vector<char>(m));
        
        for(int j=0;j<n;j++)
        {
            
            for(int i=0;i<m;i++)
            {
               ans[j][m-i-1] = box[i][j]; 
            }
            // reverse(ans[j].begin(),ans[j].end());
        }
        
        return ans;
        
    }
};
