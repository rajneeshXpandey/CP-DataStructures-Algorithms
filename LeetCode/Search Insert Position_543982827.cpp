class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {  
        int n = nums.size();
        int i=0,j=n-1;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(target==nums[mid])
                 return mid;
            if(target<nums[mid])
                j = mid-1;
            else 
                i = mid+1;
        }  
        return j+1;
    
    }
};
