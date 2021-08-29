class Solution {
public:

    vector<int> findAnagrams(string s, string p) {
       
        map<char,int> mp;
        vector<int> ans;
        
        for(char c: p)
            mp[c]++;
        
        int i=0,j=0;
        int n = s.size();
        int count = mp.size();
        
        while(j<n){
            mp[s[j]]--;
            if(mp[s[j]]==0)
                count--;
            if(j-i+1==p.size()){
                if(count==0)
                    ans.push_back(i);
                mp[s[i]]++;
                if(mp[s[i]]==1)
                    count++;
                i++; 
            }
            j++;
        }
        return ans;
    }
};
