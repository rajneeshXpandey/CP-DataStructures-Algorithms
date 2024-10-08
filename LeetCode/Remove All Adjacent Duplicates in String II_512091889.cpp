class Solution {
public:
    string removeDuplicates(string s, int k) {
//       <---------Stack----------->  O(N)
        // checking for non empty of stack is important
       stack<pair<char,int>> st;
       st.push(make_pair(s[0],1));
       for(int i=1;i<s.size();i++)
       {
           if(!st.empty() and st.top().first == s[i])
                st.top().second++;
           else 
               st.push(make_pair(s[i],1));
           
           if(!st.empty() and st.top().second == k)
               st.pop();
       }
        
       string ans="";
       while(!st.empty())
       {
           auto tp = st.top();
           st.pop();
           for(int i=0;i<tp.second;i++)
                ans += tp.first;
       }
       reverse(ans.begin(),ans.end());
        
       return ans; 

           
 //      <------------Recursive-------------->    
        
        
        
        
    }
};
