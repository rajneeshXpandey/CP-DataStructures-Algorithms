class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //moore'e voting algorithm
      // time : O(n) and   space : O(1)
      int major = nums[0];
      int cnt = 1;
       int n = nums.size();
      for(int i=0;i<n;i++)
      {
        if(nums[i]==major)
           cnt++;
        else
        {
          cnt--;
          if(cnt==0)
            { major = nums[i];
              cnt = 1; 
            }
        }          
      }
      
      cnt = 0;
      for(auto x : nums)
      {
        if(x==major)
           cnt++;
      }
      
      return (cnt>(n/2))?major:-1;
      
    }
};
