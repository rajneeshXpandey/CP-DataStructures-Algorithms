#define pic pair<int,char>
class Solution {
public:
    string frequencySort(string s) {
      string ans = "";
        unordered_map<char,int> mp;
      for(int i=0;i<s.size();i++)
        mp[s[i]]++;
      // ***here key==>s[i] and value==>frequency
      priority_queue<pic> mnheap;
      for(auto it=mp.begin();it!=mp.end();it++)
        mnheap.push({it->second,it->first});        
      while(mnheap.size()>0)
      {
        int freq = mnheap.top().first;
        while(freq--)
           ans += mnheap.top().second;
        mnheap.pop();
      }
      
      return ans;
    }
};
