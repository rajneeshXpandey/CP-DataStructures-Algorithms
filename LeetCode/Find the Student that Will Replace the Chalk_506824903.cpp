class Solution {
public:
    int chalkReplacer(vector<int>& chalk, long long k) {
        long long sum = 0;
        for(auto c : chalk)
             sum += c;
        
        k = k%sum;
        
        for(int i=0;i<chalk.size();i++)
        {
            if(k<chalk[i])
                 return i;
            else 
                k = k - chalk[i];
        }
        
        return chalk.size()-1;
    }
};
