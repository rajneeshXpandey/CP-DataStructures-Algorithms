class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
       int m = matrix.size(); 
       int n = matrix[0].size();
       cout<<m<<" "<<n<<endl;
       int i = 0;
       int j = n-1;
      
        while(i<m and j>=0)
        {
          if(matrix[i][j] == target)
             return true;
          else if(matrix[i][j] > target)
            j--;
          else if(matrix[i][j]<target)
            i++;          
        }     
      return false;
    }
};
