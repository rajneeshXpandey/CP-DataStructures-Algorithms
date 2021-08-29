class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      vector<vector<int>> ans;
      priority_queue<pair<int,vector<int>> > mxheap;
      int n =points.size();
      for(int i=0;i<n;i++)
      {mxheap.push({ (points[i][0]*points[i][0]+points[i][1]
          *points[i][1]),points[i] });
        
        if(mxheap.size()>k)
          mxheap.pop();
      }
      
      while(mxheap.size()>0)
      {
        ans.push_back(mxheap.top().second);
        mxheap.pop();
      }
      
      return ans;
    }
};
