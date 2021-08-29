class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
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
    }
};
