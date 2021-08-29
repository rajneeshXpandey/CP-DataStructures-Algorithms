class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int ans = 0,sum = 0, n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum<1){
                ans += 1-sum; 
                sum += 1-sum;
            }
        }
        
        return (ans==0)?1:ans;
        
    }
};
