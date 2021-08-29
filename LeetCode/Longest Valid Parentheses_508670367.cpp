class Solution {
public:
    int longestValidParentheses(string s) {
        int mxsz = 0;
        int currsz = 0;
        int c = 0;
        int o = 0;
        for(int i=0;i<s.size();i++)
            {
              if(s[i]=='(')
                 o++;
              if(s[i]==')')
                  c++;
              if(o<c)
               { currsz = 0;
                 o=0,c=0;
                }
              if(o==c)
                 mxsz = max(o+c,mxsz);               
            }
        o=0,c=0;
        int mxsz1 = 0;
          for(int i=s.size()-1;i>=0;i--)
            {
              if(s[i]=='(')
                 o++;
              if(s[i]==')')
                  c++;
              if(o>c)
               { currsz = 0;
                 o=0,c=0;
                }
              if(o==c)
                 mxsz1 = max(o+c,mxsz1);               
            } 
       return max(mxsz1,mxsz); 
    }
};
