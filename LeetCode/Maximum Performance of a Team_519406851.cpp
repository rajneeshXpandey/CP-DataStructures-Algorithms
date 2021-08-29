class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& 
        efficiency, int k) {
        const int mod = 1e9+7;
        priority_queue<int,vector<int>,greater<int> > pq;
        vector<pair<int, int> > data;
        for(int i=0;i<speed.size();i++){
            data.push_back({efficiency[i],speed[i]});
        }
        sort(data.rbegin(),data.rend());
        long long sum = 0;
        long long ans = 0;
        
        for(int i=0;i<speed.size();i++){
            pq.push(data[i].second);
            sum = (sum+data[i].second);
            if(pq.size()>k){ 
              sum -= pq.top();
              pq.pop();
            }
           ans = max(ans,sum*data[i].first); 
        }
        
        return ans%(int)mod;
    }
};
