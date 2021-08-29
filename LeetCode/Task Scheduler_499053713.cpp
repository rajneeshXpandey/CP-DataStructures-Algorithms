class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
             
        int time = 0;
        unordered_map<char,int> mp;
      
        for(auto x : tasks)
            mp[x]++;
        
        priority_queue<pair<int,char> > mxh;
        
        for(auto m:mp) 
            mxh.push(make_pair(m.second,m.first));
        
      while(!mxh.empty())  
       { 
           int rem = n+1-mxh.size();
           int idle = rem;
          while(rem>0)
             {
              time++;
              rem--;
              }
          int sz = mxh.size();
          int t = min(n+1,sz);
          vector<pair<int,char>> v(t);
          for(int i=0;i<t;i++)
           { 
              v[i] = mxh.top();
              mxh.pop();
              time++;
            v[i].first--;
           }

         for(auto val : v) 
            if(val.first>0) 
              mxh.push(val);
         if(idle>0 and mxh.size()==0)
             time -= idle;
          
          
       }
        
        return time;
    }
};
