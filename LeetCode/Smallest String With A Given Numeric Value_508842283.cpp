class Solution {
public:
    string getSmallestString(int n, int k) {
        string s = "";
        for(int i=1;i<=(k/26);i++)
            s.push_back('z');

         if(k%26)
           s.push_back((char)('a'+(k%26)-1));
        
        int rem=n-s.size(); 
        
     int i = s.size()-1;
        
     while(s.size()<n)
     {
         if(s[i]=='a')
             i--;
         s[i]--;
         s.push_back('a');
     }
       reverse(s.begin(),s.end());
       return s; 
    }
};
