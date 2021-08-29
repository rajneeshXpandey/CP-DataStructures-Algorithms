class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1,mid=0,left=0,right=0;
        
        while(l<=r){
            mid = (l+r)/2;
            left = (mid>0)?(nums[mid-1]):INT_MIN;
            right = (mid<n-1)?(nums[mid+1]):INT_MIN;
            if(nums[mid]>right && nums[mid]>left)
                return mid;
            else if(nums[mid]<right)
                l = mid+1;
            else 
                r = mid-1;
        }
        return mid;
    }
};
