class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int st=0,end = 0;
        int farthest = 0;
        int jump = 0;
        for(int i=0;i<n-1;i++){
            farthest = max(farthest,i+nums[i]);
            if(i==end){
                end = farthest;
                jump++;
            }
        }
        return jump;
      /**   
                  i ef              jump = 2;     
            2 3 1 1 4
      */
        
    }
};
