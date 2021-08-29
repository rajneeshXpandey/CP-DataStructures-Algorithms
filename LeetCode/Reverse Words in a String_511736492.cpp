class Solution {
public:
    string reverseWords(string s) {
        
        int i=s.length()-1;
        
        string ans = "";
        
        while(i>=0)
        {
            while(i>=0 and s[i]==' ')
                i--;
            int j = i;
            
            while(i>=0 and s[i]!=' ')
                i--;
           
            // for starting "  " spaces
            if(i<0 and j<0) break;
            
            if(ans.empty())
            {
                ans+=s.substr(i+1,j-i);
            }
            else 
            {
                ans+=" "+s.substr(i+1,j-i);
            }
        }
        
        return ans;
        
    }
};
