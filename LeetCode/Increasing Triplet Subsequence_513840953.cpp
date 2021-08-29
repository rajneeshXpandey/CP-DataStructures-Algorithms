class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n<3)
             return false;
        // this is the same as the BS sloution of the LIS
        // it will not give the actual ans but it surelly tell weather 
            it exist or not
        int n1 =INT_MAX, n2 = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=n1)
            {
               n1 = nums[i];
            }
            else if(nums[i]<=n2)
            {
                n2 = nums[i];
            }
            else{
                return true;
            }
        }
        return false;
    }
};
