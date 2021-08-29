class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> st;
        int count =0; 
        int o=0;
        int c=0;
        int extraC=0;
       for(auto c: S) 
       { 
           
               if(c == '(')
            {
                st.push(c);
            }
            else if(c == ')')
            {
                if(!st.empty())
                  st.pop() ;
                else
                    extraC++;
            }
            

       
       }  
        int ans = st.size();
           
           return ans+extraC;
        
    }
};
