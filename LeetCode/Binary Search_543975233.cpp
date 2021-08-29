class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i=0,j=n-1;
        while(i<=j){
            int mid = i+j/2;
            if(target==nums[mid])
                 return mid;
            if(target<nums[mid])
                j--;
            else 
                i++;
        }  
        return -1;
    }
};
