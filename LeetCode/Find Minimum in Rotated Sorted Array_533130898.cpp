class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1,mid=0,left=0,right=0;
        if(n==1) return nums[0];
        while(l<=r){
            mid = (l+r)/2;
            left = (mid-1+n)%n;
            right = (mid+1)%n;
            if(nums[mid]<nums[right] and nums[mid]<nums[left])
                {
                return nums[mid];
            }
            else if(nums[mid]<=nums[r])
                r = mid-1;
            else 
                l = mid+1;
         
        }
        return -1;
    }
};
