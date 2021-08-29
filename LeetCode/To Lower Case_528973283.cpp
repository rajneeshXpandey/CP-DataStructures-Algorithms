class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch-'A'>=0 and ch-'A'<=25){
                s[i] = ch-'A'+'a';
            }
        }
        
        return s;
    }
};
