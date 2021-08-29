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
        
        
        
       //  if(n==1) return 0;
       //  if(nums[0]==0) return -1;
       //  int farthest = nums[0];
       //  int jump = 1;
       //  int st = 1;
       //  int end = farthest;
       //  while(st<n){
       //      int j = st;
       //      while(j<=end){
       //          if(farthest<min(n-1,j+nums[st])){
       //             farthest=min(n-1,j+nums[st]);
       //             jump++;
       //          }
       //          j++;
       //      }
       //      if(farthest==n-1) return jump;
       //      st = end;
       //      end = farthest;  
       // }
       return jump;
    }
};
