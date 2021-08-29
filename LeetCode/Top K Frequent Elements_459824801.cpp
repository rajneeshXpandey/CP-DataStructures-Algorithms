#define pii pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      vector<int> ans;
        unordered_map<int,int> mp;
      for(int i=0;i<nums.size();i++)
        mp[nums[i]]++;
      // ***here key==>nums[i] and value==>frequency
      priority_queue<pii,vector<pii>,greater<pii>> mnheap;
      for(auto it=mp.begin();it!=mp.end();it++)
      {
        mnheap.push({it->second,it->first});        
        if(mnheap.size()>k)
            mnheap.pop();
      }
      while(mnheap.size()>0)
      {
        ans.push_back(mnheap.top().second);
        mnheap.pop();
      }
      
      return ans;
    }
};
