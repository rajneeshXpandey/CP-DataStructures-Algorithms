class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> mnheap;
      
        for(int i=0;i<nums.size();i++)
        {
          mnheap.push(nums[i]);          
          if(mnheap.size()>k)
            mnheap.pop();
        }
      
      return mnheap.top();
    }
};
