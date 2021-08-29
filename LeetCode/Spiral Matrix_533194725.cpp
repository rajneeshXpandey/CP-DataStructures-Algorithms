    int dr[] = { 0, 1, 0, -1 };
    int dc[] = { 1, 0, -1, 0 };

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
   /**     
        vector<int> spiral;
        int m = matrix.size(),n = matrix[0].size();
        int lc = 0, rc = n -1 , tr = 0 ,br = m-1;
        // cout<<"----"<<endl;
        while(lc<=rc and tr<=br){
            // cout<<lc<<' '<<rc<<' '<<tr<<' '<<br<<endl;
            for(int i=lc;i<=rc;i++){
                spiral.push_back(matrix[tr][i]);
            }
            tr++;
            for(int j=tr;j<=br;j++){
                spiral.push_back(matrix[j][rc]);
            }
            rc--;
             if(tr<=br)
           { for(int k=rc;k>=lc;k--){
                spiral.push_back(matrix[br][k]);
            }
            br--;
           }
           if(lc<=rc)
            {for(int w=br;w>=tr;w--){
                spiral.push_back(matrix[w][lc]);
            }
            lc++;}
            // cout<<lc<<' '<<rc<<' '<<tr<<' '<<br<<endl;
        }
        return spiral;
  **/      
        
        
    vector<int> ans;

    if (matrix.size() == 0)
        return ans;

    int R = matrix.size(), C = matrix[0].size();
    vector<vector<bool> > seen(R, vector<bool>(C, false));

    int r = 0, c = 0, di = 0;

    // Iterate from 0 to R * C - 1
    for (int i = 0; i < R * C; i++) {
        ans.push_back(matrix[r][c]);
        seen[r][c] = true;
        int cr = r + dr[di];
        int cc = c + dc[di];

     if (0 <= cr && cr < R && 0 <= cc && cc < C
            && !seen[cr][cc]) {
            r = cr;
            c = cc;
        }
        else {
            di = (di + 1) % 4;
            r += dr[di];
            c += dc[di];
        }
    }
    return ans;

    }
};
