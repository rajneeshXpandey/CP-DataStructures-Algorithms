class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        map<char,int> mp;
        for(auto c: t){
            mp[c]++;
        }
        int count = mp.size();
        int i=0,j=0,len=INT_MAX;
        string ans = "";
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    count--;
            }
            if(count==0){
                 while(i<=j and count==0){
                    if(mp.find(s[i]) != mp.end())
                    {
                        mp[s[i]]++;
                        if(mp[s[i]]>0)
                             count++;
                        else i++;
                    }
                    else
                       i++;
                }
                if(j-i+1<len){
                    len = j-i+1;
                    ans = s.substr(i,j-i+1);
                }
                i++;
            } 
            j++;
        }
        
        return ans;
        
    }
};
