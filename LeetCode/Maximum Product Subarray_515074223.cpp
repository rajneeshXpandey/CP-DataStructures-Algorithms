class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // base case : 
        //1. if all -ve and 0  but -ve are not continuous --->ans = 0
        //2. one element with -ve value.
        if(n==1)
            return nums[0];
        bool flag = 0;
        int mx = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            { 
              flag=1;
            }
            mx = max(nums[i],mx);
        } 
        // min and max so far till i
        int minprod = nums[0];
        int maxprod = nums[0];
        
        int ans = nums[0];
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]==0)
            {
                minprod = 1;
                maxprod = 1;
                continue;
            }
            
            int temp = maxprod;
            maxprod = max(nums[i], max(minprod*nums[i],maxprod*nums[i]
                ));
            minprod = min(nums[i], min(minprod*nums[i],temp*nums[i]));
            
            ans = max(ans,maxprod);
            
           // cout<<maxprod<<" "<<minprod<<" "<<ans<<endl;
        }
        
        return (ans<0 and !flag)?mx:ans;
        
        
    }
};
