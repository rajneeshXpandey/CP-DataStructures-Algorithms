class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int c = 0;
        for(int i=left;i<=right;i++)
        {
            for(auto r : ranges)
            {
                if(i>=r[0] and i<=r[1])
                    { c++;
                      break;
                    }
            }
        }
        
        if(c==right-left+1)
            return 1;
        else
            return false; 
    }
};
