class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest=0, currReach = 0 , n = nums.size();
        if(n==1) return true;
        for(int i=0;i<n-1;i++){
            farthest = max(farthest,nums[i]+i);
            if(i==currReach){
                currReach = farthest;
            }
            if(currReach>=n-1)
                return true;
        } 
        return false;
    }
};
