class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        
         int n = nums.size();
        
        if(n<=1)
            return 1;
       
        vector<int> pre(n);
        int odds = (nums[1]),evens =(nums[0]);
        pre[0] = (nums[0]);
        pre[1] = (nums[1]);
        for(int i=2;i<n;i++){ 
            pre[i] = (pre[i-2] + nums[i]);  
            if(i%2)  odds += nums[i];
            else evens += nums[i];
        }
        
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0) 
            {
                
                 int even = odds - ((i-1>=0)?pre[i-1]:0) + ((i-2>=0
                     )?pre[i-2]:0);
                 int odd = evens - pre[i] + ((i-1>=0)?pre[i-1]:0); 
                 if(even == odd)
                       count++;
          
            }
            else 
            {
                 int even = odds - pre[i] + ((i-1>=0)?pre[i-1]:0);
                 int odd = evens - ((i-1>=0)?pre[i-1]:0) + ((i-2>=0
                     )?pre[i-2]:0);
                 if(even == odd)
                       count++;
                
            }
        }
        
        return count;
    }
};
