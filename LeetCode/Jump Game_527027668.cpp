class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest=0, end = 0 , n = nums.size();
        if(n==1) return true;
        for(int i=0;i<n-1;i++){
            farthest = max(farthest,nums[i]+i);
            if(i==end){
                end = farthest;
            }
            if(end>=n-1)
                return true;
        }
        
        return false;
    }
};
